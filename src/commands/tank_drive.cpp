#include "tank_drive.hpp"

#include "../subsystems/subsystems.hpp"
#include "../ui/user_interface.hpp"

Tank_Drive::Tank_Drive() : half_speed (false) {
	Requires(Subsystems::drive_base);
	Subsystems::drive_base->reset_encoders();
}

void Tank_Drive::Execute() {
	if (UI::left_joystick->BUTTON_2->Get()) {
		half_speed = true;
	}
	if (UI::right_joystick->BUTTON_2->Get()) {
		half_speed = false;
	}

	float left, right;
	if (UI::left_joystick->TRIGGER->Get() || UI::right_joystick->TRIGGER->Get()) {
		left = -1 * UI::right_joystick->get_y();
		right = -1 * UI::left_joystick->get_y();
	} else {
		left = UI::left_joystick->get_y();
		right = UI::right_joystick->get_y();
	}

	float left_difference = left - left_speed;
	if (left_difference > MAX_CHANGE) {
		left_speed += MAX_CHANGE;
	} else if (left_difference < -MAX_CHANGE) {
		left_speed -= MAX_CHANGE;
	} else {
		left_speed += left_difference;
	}

	float right_difference = right - right_speed;
	if (right_difference > MAX_CHANGE) {
		right_speed += MAX_CHANGE;
	} else if (right_difference < -MAX_CHANGE) {
		right_speed -= MAX_CHANGE;
	} else {
		right_speed += right_difference;
	}

	left_speed = constrain(left_speed);
	right_speed = constrain(right_speed);

	if (half_speed) {
		Subsystems::drive_base->set_motors_normalized(left_speed / 2, right_speed / 2);
	} else {
		Subsystems::drive_base->set_motors_normalized(left_speed, right_speed);
	}
}

bool Tank_Drive::IsFinished() {
	return false;
}

void Tank_Drive::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}

float Tank_Drive::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
