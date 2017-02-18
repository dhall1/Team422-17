#pragma once

#include <WPILib.h>

class Shooter_Command : public frc::Command {
public:
	Shooter_Command();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted() {};
	void End();
};
