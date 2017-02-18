#include "tank_drive.hpp"

#include "../subsystems/subsystems.hpp"
#include "../ui/user_interface.hpp"

Tank_Drive::Tank_Drive() {
	Requires(Subsystems::drive_base);
}

void Tank_Drive::Execute() {
	float left = UI::left_joystick->get_y();
	float right = UI::right_joystick->get_y();

	Subsystems::drive_base->set_motors_normalized(left, right);
}

bool Tank_Drive::IsFinished() {
	return false;
}

void Tank_Drive::End() {
	Subsystems::drive_base->set_motors_normalized(0, 0);
}
