#include "subsystems.hpp"

Ball_Intake *Subsystems::ball_intake = nullptr;
Compressor_System *Subsystems::compressor_system = nullptr;
Drive_Base *Subsystems::drive_base = nullptr;
Gear_Intake *Subsystems::gear_intake = nullptr;
Lift *Subsystems::lift = nullptr;
Shooter *Subsystems::shooter = nullptr;

void Subsystems::initialize() {
	ball_intake = new Ball_Intake();
	compressor_system = new Compressor_System();
	drive_base = new Drive_Base();
	gear_intake = new Gear_Intake();
	lift = new Lift();
	shooter = new Shooter();
}

