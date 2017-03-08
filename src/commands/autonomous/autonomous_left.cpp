#include "autonomous_left.hpp"

#include "drive_straight.hpp"
#include "turn.hpp"

Autonomous_Left::Autonomous_Left() {
	AddSequential(new Drive_Straight(2604));
	AddSequential(new Turn(60));
	AddSequential(new Drive_Straight(3727));
}
