#include "robot.hpp"

#include "subsystems/subsystems.hpp"
#include "ui/user_interface.hpp"
#include "commands/autonomous/drive_straight.hpp"

void Robot::RobotInit() {
	Subsystems::initialize();
	UI::initialize();
	autonomousChooser = SendableChooser<Command*>();
	autonomousChooser.AddObject("Baseline Autonomous (Timed)", new Autonomous_Baseline());
	autonomousChooser.AddDefault("Center Autonomous", new Autonomous_Center());
	autonomousChooser.AddObject("Left Autonomous", new Autonomous_Left());
	autonomousChooser.AddObject("Left Boiler Autonomous", new Autonomous_Boiler_Left());
	autonomousChooser.AddObject("Right Autonomous", new Autonomous_Right());
	autonomousChooser.AddObject("Right Boiler Autonomous", new Autonomous_Boiler_Right());
	SmartDashboard::PutData("Autonomous Modes", &autonomousChooser);
	camera1 = CameraServer::GetInstance()->StartAutomaticCapture();
	camera2 = CameraServer::GetInstance()->StartAutomaticCapture();
	camera1.SetFPS(10);
	camera2.SetFPS(10);
	SmartDashboard::PutNumber("Gyro Correction", 0.2);
}

void Robot::DisabledInit() {

}

void Robot::AutonomousInit() {
	Constant::GYRO_CORRECTION = SmartDashboard::GetNumber("Gyro Correction", 0.2);
	Subsystems::drive_base->reset_gyro();
	Subsystems::drive_base->reset_encoders();
	autonomous = (Command*) autonomousChooser.GetSelected();
	if (autonomous != nullptr) {
		autonomous->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Drive Base Left Encoder Position", Subsystems::drive_base->get_left_encoder_position());
	SmartDashboard::PutNumber("Drive Base Right Encoder Position", Subsystems::drive_base->get_right_encoder_position());
	SmartDashboard::PutNumber("Gyro Angle", Subsystems::drive_base->get_angle());
}

void Robot::TeleopInit() {
	if (autonomous != nullptr) {
		autonomous->Cancel();
	}
	Subsystems::ball_intake->set_intake_value(DoubleSolenoid::Value::kReverse);
	Subsystems::drive_base->reset_encoders();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Back Shooter", Subsystems::shooter->get_front_speed());
	SmartDashboard::PutNumber("Front Shooter", Subsystems::shooter->get_back_speed());
	SmartDashboard::PutNumber("Drive Base Left Encoder Position", Subsystems::drive_base->get_left_encoder_position());
	SmartDashboard::PutNumber("Drive Base Right Encoder Position", Subsystems::drive_base->get_right_encoder_position());
	SmartDashboard::PutNumber("Gyro Angle", Subsystems::drive_base->get_angle());
}

START_ROBOT_CLASS(Robot);
