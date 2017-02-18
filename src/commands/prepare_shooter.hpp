#pragma once

#include <WPILib.h>

class Prepare_Shooter : public frc::Command {
public:
	Prepare_Shooter(bool on);
	void Initialize();
	void Execute() {};
	bool IsFinished();
	void Interrupted() {};
	void End() {};
private:
	bool on;
};


