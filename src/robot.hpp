#pragma once

#include "commands/autonomous/autonomous_left.hpp"
#include <WPILib.h>

class Robot : public frc::IterativeRobot {
public:
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
private:
	Autonomous_Left *autonomous;
//	Command *autonomous;
//	SendableChooser<Command*> autonomousChooser;
};


