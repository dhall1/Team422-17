#include "drive_straight.hpp"

#include <math.h>

#include "../../subsystems/subsystems.hpp"

Drive_Straight::Drive_Straight(int distance, float speed) :
ticks (abs(distance)),
angle (Subsystems::drive_base->get_angle()),
left_speed (speed),
right_speed (speed),
is_finished (false) {
	Requires(Subsystems::drive_base);
}

void Drive_Straight::Initialize() {
	SmartDashboard::PutNumber("Drive Straight set point (encoder ticks)", ticks);
	Subsystems::drive_base->reset_encoders();
	Subsystems::drive_base->set_motors_normalized(-left_speed, -right_speed);
}

void Drive_Straight::Execute() {
	float correction = Subsystems::drive_base->get_angle() - angle;
	correction *= 0.075;
	correction += 1;
	Subsystems::drive_base->set_motors_normalized(-left_speed, -1 * right_speed * correction);
	SmartDashboard::PutNumber("Drive Base Left Encoder Speed", Subsystems::drive_base->get_left_encoder_speed());
	SmartDashboard::PutNumber("Drive Base Right Encoder Speed", Subsystems::drive_base->get_right_encoder_speed());
	SmartDashboard::PutNumber("Gyro Angle", Subsystems::drive_base->get_angle());
}

bool Drive_Straight::IsFinished() {
	int left_count = abs(Subsystems::drive_base->get_left_encoder_position());
	int right_count = abs(Subsystems::drive_base->get_right_encoder_position());
	bool is_left_done = left_count > ticks;
	bool is_right_done = right_count > ticks;
	SmartDashboard::PutNumber("Drive Base Left Position", left_count);
	SmartDashboard::PutNumber("Drive Base Right Position", right_count);
	SmartDashboard::PutBoolean("Is left done?", is_left_done);
	SmartDashboard::PutBoolean("Is right done?", is_right_done);
	is_finished = is_left_done || is_right_done;
	return is_finished;
}

void Drive_Straight::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

void Drive_Straight::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}
