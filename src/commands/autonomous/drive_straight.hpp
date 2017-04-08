#pragma once

#include "timeout_command.hpp"

namespace Constant {
	static float GYRO_CORRECTION = 0.2;
}

class Drive_Straight : public Timeout_Command {
public:
	Drive_Straight(int distance, float speed, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	int distance;
	bool direction;
	float angle;
	float left_speed, right_speed;
};


