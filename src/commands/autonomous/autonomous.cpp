#include "autonomous.hpp"

#include "drive_straight.hpp"
#include "../../subsystems/subsystems.hpp"
#include "turn.hpp"

Autonomous::Autonomous() {
	AddSequential(new Drive_Straight(-3909));
	AddSequential(new Turn(-90));
	AddSequential(new Drive_Straight(-500));
}
