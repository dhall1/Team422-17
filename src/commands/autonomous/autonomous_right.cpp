#include "autonomous_right.hpp"

#include "drive_straight.hpp"
#include "turn.hpp"

Autonomous_Right::Autonomous_Right() {
	AddSequential(new Drive_Straight(2604));
	AddSequential(new Turn(-60));
	AddSequential(new Drive_Straight(3727));
}
