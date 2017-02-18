#pragma once

#include <WPILib.h>

class Drive_Straight : public Command {
public:
	Drive_Straight(float distance);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	float ticks;
	const double PI = 3.141592653589793238463;
	// Diameter of wheels in inches
	const double DIAMETER = 4;
	const double TICK_PER_REVOLUTION = 12;
	const double CIRCUMFERENCE = PI * DIAMETER;
	float distance_to_ticks(float input);
};


