#pragma once

#include <WPILib.h>

#include "commands/autonomous/autonomous.hpp"

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
};


