#include "autonomous.hpp"

#include "drive_straight.hpp"
#include "../../subsystems/subsystems.hpp"
#include "turn.hpp"

Autonomous::Autonomous() {
//	AddSequential(new Drive_Straight(1222, 0.4));
	AddSequential(new Turn(90));
	Wait(1);
	AddSequential(new Turn(-90));
	Wait(1);
	AddSequential(new Turn(90));
	Wait(1);
	AddSequential(new Turn(-90));
}
