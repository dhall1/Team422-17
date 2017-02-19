#include "lift_command.hpp"

#include "../subsystems/subsystems.hpp"

Lift_Command::Lift_Command(bool on) :
on (on) {
	Requires(Subsystems::lift);
}

void Lift_Command::Initialize() {
	if (on) {
		Subsystems::lift->set_motor(0.6);
		Subsystems::ball_intake->set_intake_motor(0.5);
	} else {
		Subsystems::lift->set_motor(0);
		Subsystems::ball_intake->set_intake_motor(0);
	}
}

void Lift_Command::Execute() {

}

bool Lift_Command::IsFinished() {
	return true;
}

void Lift_Command::Interrupted() {

}

void Lift_Command::End() {

}
