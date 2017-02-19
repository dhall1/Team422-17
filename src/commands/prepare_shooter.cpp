#include "prepare_shooter.hpp"

#include "../subsystems/subsystems.hpp"

Prepare_Shooter::Prepare_Shooter(bool on) :
on (on) {
	Requires(Subsystems::shooter);
}

void Prepare_Shooter::Initialize() {
	if (on) {
		Subsystems::shooter->set_top_speed(.2);
		Subsystems::shooter->set_bottom_speed(0.5);
	} else {
		Subsystems::shooter->set_top_speed(0);
		Subsystems::shooter->set_bottom_speed(0);
	}
}

bool Prepare_Shooter::IsFinished() {
	return true;
}
