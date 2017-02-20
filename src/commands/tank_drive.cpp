#include "tank_drive.hpp"

#include "../subsystems/subsystems.hpp"
#include "../ui/user_interface.hpp"

Tank_Drive::Tank_Drive() {
	Requires(Subsystems::drive_base);
	Subsystems::drive_base->reset_encoders();
}

void Tank_Drive::Execute() {
	float left, right;
	if (UI::launchpad->SWITCH_1->Get()) {
		left = -1 * UI::right_joystick->get_y();
		right = -1 * UI::left_joystick->get_y();
	} else {
		left = UI::left_joystick->get_y();
		right = UI::right_joystick->get_y();
	}

	Subsystems::drive_base->set_motors_normalized(left, right);

	SmartDashboard::PutNumber("Drive Base Left Encoder Speed", Subsystems::drive_base->get_left_encoder_speed());
	SmartDashboard::PutNumber("Drive Base Left Position", Subsystems::drive_base->get_left_encoder_position());
	SmartDashboard::PutNumber("Drive Base Right Encoder Speed", Subsystems::drive_base->get_right_encoder_speed());
	SmartDashboard::PutNumber("Drive Base Right Position", Subsystems::drive_base->get_right_encoder_position());
	SmartDashboard::PutNumber("Gyro Angle", Subsystems::drive_base->get_angle());
}

bool Tank_Drive::IsFinished() {
	return false;
}

void Tank_Drive::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}
