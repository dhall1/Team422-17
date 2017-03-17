#pragma once

#include "timeout_command.hpp"

class Turn : public Timeout_Command {
public:
	Turn(float angle, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float angle;
	bool direction;
	float left_speed;
	float right_speed;
};


