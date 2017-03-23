#include "ball_intake.hpp"

#include "../port_mapping.hpp"

Ball_Intake::Ball_Intake() :
Subsystem("Ball_Intake"),
intake_solenoid (new DoubleSolenoid(Ports::Solenoids::BALL_INTAKE_FORWARD, Ports::Solenoids::BALL_INTAKE_REVERSE)) {}

void Ball_Intake::set_intake_value(DoubleSolenoid::Value value) {
	intake_solenoid->Set(value);
}
