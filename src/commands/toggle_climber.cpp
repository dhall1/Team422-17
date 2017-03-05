#include "toggle_climber.hpp"

#include "../subsystems/subsystems.hpp"

Toggle_Climber::Toggle_Climber(bool on) : on (on) {
	Requires(Subsystems::climber);
}

void Toggle_Climber::Initialize() {
	if (on) {
		Subsystems::climber->set_motor(0.9);
	} else {
		Subsystems::climber->set_motor(0);
	}
}

bool Toggle_Climber::IsFinished() {
	return true;
}
