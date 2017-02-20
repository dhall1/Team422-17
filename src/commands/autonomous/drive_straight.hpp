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
	int ticks;
	float angle;
	float left_speed, right_speed;
	bool is_finished;
};


