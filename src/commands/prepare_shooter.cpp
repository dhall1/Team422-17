#include "prepare_shooter.hpp"

#include "../subsystems/subsystems.hpp"

Prepare_Shooter::Prepare_Shooter(bool on) :
on (on) {
	Requires(Subsystems::shooter);
	Requires(Subsystems::lift);
	Requires(Subsystems::ball_intake);
}

void Prepare_Shooter::Initialize() {
	if (on) {
		printf("Turning on shooter equipment...\n");
		Subsystems::shooter->set_top_speed(.15);
		Subsystems::shooter->set_bottom_speed(0.5);
		Subsystems::lift->set_motor(0.6);
		Subsystems::ball_intake->set_intake_motor(0.5);
	} else {
		printf("Turning off shooter equipment...\n");
		Subsystems::shooter->set_top_speed(0);
		Subsystems::shooter->set_bottom_speed(0);
		Subsystems::lift->set_motor(0);
		Subsystems::ball_intake->set_intake_motor(0);
	}
}

bool Prepare_Shooter::IsFinished() {
	return true;
}
