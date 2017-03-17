#pragma once

#include "timeout_command.hpp"

class Drive_Straight : public Timeout_Command {
public:
	Drive_Straight(int distance, float speed, unsigned int max_iterations, double timeout);
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
	unsigned int max_iterations;
	unsigned int current_iterations = 0;
};


