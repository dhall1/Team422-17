#include "drive_straight.hpp"

#include <math.h>

#include "../../subsystems/subsystems.hpp"

Drive_Straight::Drive_Straight(int distance, float speed, unsigned int max_iterations, double timeout) :
Timeout_Command(timeout),
distance (distance),
direction (distance > 0),
angle (Subsystems::drive_base->get_angle()),
left_speed (direction ? -speed : speed),
right_speed (direction ? -speed : speed),
max_iterations (max_iterations) {
	Requires(Subsystems::drive_base);
	Subsystems::drive_base->reset_encoders();
}

void Drive_Straight::Initialize() {
	Subsystems::drive_base->reset_encoders();
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed);
	angle = Subsystems::drive_base->get_angle();
}

void Drive_Straight::Execute() {
	// Testing to slow down within a certain distance of the target
//	bool is_left_close = (abs(Subsystems::drive_base->get_left_encoder_position()) + 500) > abs(distance);
//	bool is_right_close = (abs(Subsystems::drive_base->get_right_encoder_position()) + 500) > abs(distance);
//	if (is_left_close && is_right_close) {
//		if (direction) {
//			left_speed = -0.2;
//			right_speed = -0.2;
//		} else {
//			left_speed = 0.2;
//			right_speed = 0.2;
//		}
//	}
	float correction = 0;
	if (direction) {
		correction = Subsystems::drive_base->get_angle() - angle;
	} else {
		correction = angle - Subsystems::drive_base->get_angle();
	}
	correction *= 0.075;
	correction += 1;
	Subsystems::drive_base->set_motors_normalized(left_speed, right_speed * correction);
}

bool Drive_Straight::IsFinished() {
	int left_count = abs(Subsystems::drive_base->get_left_encoder_position());
	int right_count = abs(Subsystems::drive_base->get_right_encoder_position());
	int abs_distance = abs(distance);
	current_iterations++;
	bool has_reached_max_iterations = false;
	if (left_count == 0 && right_count == 0) {
		printf("Running based on iterations...\n");
		if (current_iterations > max_iterations) {
			has_reached_max_iterations = true;
		}
	}
	return (left_count > abs_distance) || (right_count > abs_distance) || has_reached_max_iterations || is_timed_out();;
}

void Drive_Straight::Interrupted() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

void Drive_Straight::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
	Subsystems::drive_base->reset_encoders();
}
