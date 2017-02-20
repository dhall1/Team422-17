#pragma once

#include <WPILib.h>

class Turn : public frc::Command {
public:
	Turn(float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float angle;
	const double PI = 3.141592653589793238463;
};


