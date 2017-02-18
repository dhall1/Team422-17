#include "ball_intake.hpp"

#include "../port_mapping.hpp"

Ball_Intake::Ball_Intake() :
Subsystem("Ball_Intake"),
intake_solenoid (new DoubleSolenoid(Ports::Solenoids::BALL_INTAKE_FORWARD, Ports::Solenoids::BALL_INTAKE_REVERSE)),
intake_motor (new CANTalon(Ports::CANBusIds::INTAKE_MOTOR)) {
	intake_solenoid->Set(DoubleSolenoid::Value::kReverse);
	intake_motor->SetInverted(true);
	intake_motor->Set(0);
}

void Ball_Intake::set_intake_value(DoubleSolenoid::Value value) {
	intake_solenoid->Set(value);
}

DoubleSolenoid::Value Ball_Intake::get_intake_value() {
	return intake_solenoid->Get();
}

void Ball_Intake::set_intake_motor(float value) {
	intake_motor->Set(value);
}
