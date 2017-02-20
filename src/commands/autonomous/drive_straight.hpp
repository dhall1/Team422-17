#pragma once

#include <WPILib.h>

class Drive_Straight : public Command {
public:
	Drive_Straight(int distance, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float distance_to_ticks(float input);

	int ticks=0;
	float left_speed=0.0, right_speed = 0.0 ;
	bool is_finished = 0;

	const double PI = 3.141592653589793238463;
	const double DIAMETER = 4;
	const double TICK_PER_REVOLUTION = 128;
	const double CIRCUMFERENCE = PI * DIAMETER;
};


