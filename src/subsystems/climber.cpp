#include "climber.hpp"

#include "../port_mapping.hpp"

Climber::Climber() :
Subsystem("Climber"),
climber1 (new CANTalon(Ports::CANBusIds::CLIMBER_MOTOR)),
climber2 (new CANTalon(Ports::CANBusIds::INTAKE_MOTOR)) {
	climber1->SetInverted(true);
	climber2->SetInverted(true);
	climber1->Set(0);
	climber2->Set(0);
}

void Climber::set_motor(float speed) {
	climber1->Set(constrain(speed));
	climber2->Set(constrain(speed));
}

float Climber::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
