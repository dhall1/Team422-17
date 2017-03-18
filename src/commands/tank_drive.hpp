#pragma once

#include <WPILib.h>

class Tank_Drive : public frc::Command {
public:
	Tank_Drive();
	void Initialize() {};
	void Execute();
	bool IsFinished();
	void Interrupted() {};
	void End();
private:
	bool half_speed;
	float left_speed = 0;
	float right_speed = 0;
	const float MAX_CHANGE = 0.03;
	float constrain(float input);
};


