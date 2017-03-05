#pragma once

#include <WPILib.h>
#include "commands/autonomous/autonomous.hpp"
#include "commands/autonomous/autonomous2.hpp"

class Robot : public frc::IterativeRobot {
public:
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
private:
	Autonomous *autonomous;
//	Command *autonomous;
//	SendableChooser<Command*> autonomousChooser;
};


