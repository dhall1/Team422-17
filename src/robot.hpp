#pragma once

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
//	ADXRS450_Gyro *gyro;
};


