#pragma once

#include <CANTalon.h>
#include <WPILib.h>

class Ball_Intake : public Subsystem {
public:
	Ball_Intake();
	void set_intake_value(DoubleSolenoid::Value value);
	DoubleSolenoid::Value get_intake_value();
	void set_intake_motor(float value);
private:
	DoubleSolenoid *intake_solenoid;
	CANTalon *intake_motor;
};


