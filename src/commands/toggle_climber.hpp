#pragma once

#include <WPILib.h>

class Toggle_Climber : public frc::Command {
public:
	Toggle_Climber(bool on);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	bool on;
};


