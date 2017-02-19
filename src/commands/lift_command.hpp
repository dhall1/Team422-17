#pragma once

#include <WPILib.h>

class Lift_Command : public frc::Command {
public:
	Lift_Command(bool on);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	bool on;
};

