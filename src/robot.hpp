#pragma once

#include <WPILib.h>

#include "commands/autonomous/autonomous_baseline.hpp"
#include "commands/autonomous/autonomous_center.hpp"
#include "commands/autonomous/autonomous_left.hpp"
#include "commands/autonomous/autonomous_boiler_left.hpp"
#include "commands/autonomous/autonomous_right.hpp"
#include "commands/autonomous/autonomous_boiler_right.hpp"

class Robot : public frc::IterativeRobot {
public:
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
private:
	Command *autonomous;
	SendableChooser<Command*> autonomousChooser;
	cs::UsbCamera camera1;
	cs::UsbCamera camera2;
};


