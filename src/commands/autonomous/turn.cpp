#include "turn.hpp"

#include "../../subsystems/subsystems.hpp"

Turn::Turn(float angle) :
angle (angle) {
	Requires(Subsystems::drive_base);
}

void Turn::Initialize() {

}

void Turn::Execute() {

}

bool Turn::IsFinished() {
	return false;
}

void Turn::Interrupted() {

}

void Turn::End() {

}


