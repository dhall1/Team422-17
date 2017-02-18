#include "robot.hpp"

#include "subsystems/subsystems.hpp"
#include "ui/user_interface.hpp"

void Robot::RobotInit() {
	Subsystems::initialize();
	UI::initialize();
//	gyro = new ADXRS450_Gyro();
//	gyro->Calibrate();
//	CameraServer::GetInstance()->StartAutomaticCapture();
}

void Robot::DisabledInit() {

}

void Robot::AutonomousInit() {

}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
//	Subsystems::shooter->set_top_speed(.5);
//	Subsystems::shooter->set_bottom_speed(0.15);
//	Subsystems::lift->set_motor(0.3);
//	Subsystems::ball_intake->set_intake_motor(0.5);
//	Subsystems::gear_intake->set_intake_value(DoubleSolenoid::Value::kOff); // kReverse for out
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
//	auto angle = gyro->GetAngle();
//	auto rate = gyro->GetRate();
//	SmartDashboard::PutNumber("Gyro Angle", angle);
//	SmartDashboard::PutNumber("Gyro Rate", rate);
}

START_ROBOT_CLASS(Robot);
