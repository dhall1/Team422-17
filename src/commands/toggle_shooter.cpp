#include "toggle_shooter.hpp"
#include "../subsystems/subsystems.hpp"

Toggle_Shooter::Toggle_Shooter(bool is_on) :
is_on (is_on) {
	Requires(Subsystems::shooter);
}

void Toggle_Shooter::Initialize() {
	if (is_on) {
		Subsystems::shooter->set_top_speed(.2);
		Subsystems::shooter->set_bottom_speed(0.5);
	} else {
		Subsystems::shooter->set_top_speed(0);
		Subsystems::shooter->set_bottom_speed(0);
	}
}

bool Toggle_Shooter::IsFinished() {
	return true;
}
