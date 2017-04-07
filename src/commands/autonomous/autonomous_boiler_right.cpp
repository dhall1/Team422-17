#include "autonomous_boiler_right.hpp"

#include "drive_straight.hpp"
#include "../../subsystems/subsystems.hpp"
#include "turn.hpp"
#include "../set_ball_intake.hpp"
#include "../toggle_shooter.hpp"
#include "../toggle_lift.hpp"

Autonomous_Boiler_Right::Autonomous_Boiler_Right() {
	AddParallel(new Toggle_Shooter(true));
	Wait(5);
	AddSequential(new Toggle_Lift(true));
	AddSequential(new Drive_Straight(-2000, 0.25, 2));
	AddSequential(new Turn(-45, 1));
	AddSequential(new Drive_Straight(-3500, 0.25, 2));
}
