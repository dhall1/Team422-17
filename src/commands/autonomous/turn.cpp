#include "turn.hpp"

#include "../../subsystems/subsystems.hpp"

Turn::Turn(float angle, double timeout) :
Timeout_Command(timeout),
angle (angle),
direction(angle > 0), // true for turning right, false for turning left
left_speed (direction ? -0.3 : 0.3),
right_speed (direction ? 0.3 : -0.3) {
	Requires(Subsystems::drive_base);
}

void Turn::Initialize() {
	Subsystems::drive_base->reset_gyro();
}

void Turn::Execute() {
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed);
}

bool Turn::IsFinished() {
	bool is_turn_done;
	if (direction) {
		is_turn_done = Subsystems::drive_base->get_angle() > angle;
	} else {
		is_turn_done = Subsystems::drive_base->get_angle() < angle;
	}
	return is_turn_done || is_timed_out();
}

void Turn::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

void Turn::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
	Subsystems::drive_base->reset_encoders();
}
