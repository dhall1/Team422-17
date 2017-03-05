#include "autonomous2.hpp"

#include "drive_straight.hpp"
#include "turn.hpp"

Autonomous2::Autonomous2() {
	AddSequential(new Drive_Straight(6848));
	AddSequential(new Turn(45));
	AddSequential(new Drive_Straight(6848));
}
