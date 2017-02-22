#include "robot.hpp"

#include "subsystems/subsystems.hpp"
#include "ui/user_interface.hpp"

void Robot::RobotInit() {
	Subsystems::initialize();
	UI::initialize();
	autonomous = new Autonomous();
}

void Robot::DisabledInit() {

}

void Robot::AutonomousInit() {
	Subsystems::drive_base->reset_gyro();
	Subsystems::drive_base->reset_encoders();
	autonomous->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	Subsystems::ball_intake->set_intake_value(DoubleSolenoid::Value::kReverse);
	autonomous->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);
