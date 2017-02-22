#include "drive_straight.hpp"

#include <math.h>

#include "../../subsystems/subsystems.hpp"

Drive_Straight::Drive_Straight(int distance) :
distance (distance),
direction (distance > 0),
angle (Subsystems::drive_base->get_angle()),
left_speed (direction ? -0.4 : 0.4),
right_speed (direction ? -0.4 : 0.4) {
	Requires(Subsystems::drive_base);
}

void Drive_Straight::Initialize() {
	SmartDashboard::PutNumber("Drive Straight set point (encoder ticks)", distance);
	Subsystems::drive_base->reset_encoders();
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed);
}

void Drive_Straight::Execute() {
	float correction = Subsystems::drive_base->get_angle() - angle;
	correction *= 0.075;
	correction += 1;
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed * correction);
	SmartDashboard::PutNumber("Drive Base Left Encoder Position", abs(Subsystems::drive_base->get_left_encoder_position()));
	SmartDashboard::PutNumber("Drive Base Right Encoder Position", abs(Subsystems::drive_base->get_right_encoder_position()));
	SmartDashboard::PutNumber("Gyro Angle", Subsystems::drive_base->get_angle());
}

bool Drive_Straight::IsFinished() {
	int left_count = abs(Subsystems::drive_base->get_left_encoder_position());
	int right_count = abs(Subsystems::drive_base->get_right_encoder_position());
	int abs_distance = abs(distance);
	return (left_count > abs_distance) || (right_count > abs_distance);
}

void Drive_Straight::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

void Drive_Straight::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}
