#include "robot.hpp"

#include "subsystems/subsystems.hpp"
#include "ui/user_interface.hpp"

void Robot::RobotInit() {
	Subsystems::initialize();
	UI::initialize();
	autonomousChooser = SendableChooser<Command*>();
	autonomousChooser.AddObject("Baseline Autonomous (Timed)", new Autonomous_Baseline());
	autonomousChooser.AddDefault("Center Autonomous", new Autonomous_Center());
	autonomousChooser.AddObject("Left Autonomous", new Autonomous_Left());
	autonomousChooser.AddObject("Right Autonomous", new Autonomous_Right());
	SmartDashboard::PutData("Autonomous Modes", &autonomousChooser);
	CameraServer::GetInstance()->StartAutomaticCapture();
}

void Robot::DisabledInit() {

}

void Robot::AutonomousInit() {
	Subsystems::drive_base->reset_gyro();
	Subsystems::drive_base->reset_encoders();
	autonomous = (Command*) autonomousChooser.GetSelected();
	if (autonomous != nullptr) {
		autonomous->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
//	printf("Left encoder: %d\n", Subsystems::drive_base->get_left_encoder_position());
//	printf("Right encoder: %d\n", Subsystems::drive_base->get_right_encoder_position());
}

void Robot::TeleopInit() {
	if (autonomous != nullptr) {
		autonomous->Cancel();
	}
	Subsystems::ball_intake->set_intake_value(DoubleSolenoid::Value::kReverse);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	printf("Gyro: %f\n", Subsystems::drive_base->get_angle());
}

START_ROBOT_CLASS(Robot);
