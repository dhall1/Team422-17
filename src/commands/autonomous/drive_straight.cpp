#include "drive_straight.hpp"

#include <math.h>

#include "../../subsystems/subsystems.hpp"

Drive_Straight::Drive_Straight(int distance, float speed) :
ticks (distance),
left_speed (speed),
right_speed (speed),
is_finished (false) {
	Requires(Subsystems::drive_base);
}

void Drive_Straight::Initialize() {
	is_finished = false;
	Subsystems::drive_base->reset_encoders();
	Subsystems::drive_base->set_motors_normalized(-left_speed, -right_speed);
}

void Drive_Straight::Execute() {
	SmartDashboard::PutNumber("Drive Base Left Encoder Speed", Subsystems::drive_base->get_left_encoder_speed());
	SmartDashboard::PutNumber("Drive Base Right Encoder Speed", Subsystems::drive_base->get_right_encoder_speed());
	SmartDashboard::PutNumber("Gyro Angle", Subsystems::drive_base->get_angle());
	int left_count = abs(Subsystems::drive_base->get_left_encoder_position());
	int right_count = abs(Subsystems::drive_base->get_right_encoder_position());
	SmartDashboard::PutNumber("Drive Base Left Position", left_count);
	SmartDashboard::PutNumber("Drive Base Right Position", right_count);
	int position = abs(ticks);
	SmartDashboard::PutNumber("Drive Straight set point (encoder ticks)", position);
	bool is_left_done = left_count > position;
	bool is_right_done = right_count > position;
	SmartDashboard::PutBoolean("Is left done?", is_left_done);
	SmartDashboard::PutBoolean("Is right done?", is_right_done);
	is_finished = is_left_done || is_right_done;
}

bool Drive_Straight::IsFinished() {
	return is_finished;
}

void Drive_Straight::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

void Drive_Straight::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

float Drive_Straight::distance_to_ticks(float input) {
	// Assuming that input is distance in feet
	float inches = input * 12;
	// Distance / circumference = # of revolutions
	float revolutions = inches / (CIRCUMFERENCE);
	// 12 ticks per revolution
	float ticks = revolutions * TICK_PER_REVOLUTION;
	return ticks;
}
