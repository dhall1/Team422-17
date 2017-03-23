#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Ball_Intake : public Subsystem {
public:
	Ball_Intake();
	void set_intake_value(DoubleSolenoid::Value value);
private:
	DoubleSolenoid *intake_solenoid;
};


