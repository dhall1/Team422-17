#include "autonomous_right.hpp"

#include "drive_straight.hpp"
#include "../../subsystems/subsystems.hpp"
#include "turn.hpp"
#include "../set_ball_intake.hpp"
#include "../set_gear_intake.hpp"

Autonomous_Right::Autonomous_Right() {
	AddSequential(new Set_Ball_Intake(DoubleSolenoid::Value::kForward));
	AddSequential(new Drive_Straight(2604, 0.25, 101, 3.05)); // 2.3
	AddSequential(new Turn(-60, 3));
	AddSequential(new Drive_Straight(3727, 0.25, 147, 4.1)); // 3.1
	AddSequential(new Set_Gear_Intake(DoubleSolenoid::Value::kForward));
}
