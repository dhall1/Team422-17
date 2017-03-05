#include "autonomous.hpp"

#include "drive_straight.hpp"
#include "../../subsystems/subsystems.hpp"
#include "turn.hpp"

Autonomous::Autonomous() {
	AddSequential(new Drive_Straight(-5478));
//	AddSequential(new Turn(-180));
//	AddSequential(new Drive_Straight(-250));
}
