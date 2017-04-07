#include "shooter_command.hpp"

#include "../subsystems/subsystems.hpp"

Shooter_Command::Shooter_Command() {
	Requires(Subsystems::shooter);
}

void Shooter_Command::Initialize() {
//	Subsystems::shooter->set_top_speed(.5);
//	Subsystems::shooter->set_bottom_speed(.15);
}

void Shooter_Command::Execute() {
//	SmartDashboard::PutNumber("Top Motor Encoder Speed", Subsystems::shooter->get_top_encoder_speed());
//	SmartDashboard::PutNumber("Top Motor Set vBus", Subsystems::shooter->get_top_speed());
//	SmartDashboard::PutNumber("Bottom Motor Encoder Speed", Subsystems::shooter->get_bottom_encoder_speed());
//	SmartDashboard::PutNumber("Bottom Motor Set vBus", Subsystems::shooter->get_bottom_speed());
}

bool Shooter_Command::IsFinished() {
	return false;
}

void Shooter_Command::End() {
	Subsystems::shooter->set_back_speed(0);
	Subsystems::shooter->set_front_speed(0);
}
