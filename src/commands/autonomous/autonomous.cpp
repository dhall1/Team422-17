#include "autonomous.hpp"

#include "drive_straight.hpp"
#include "../../subsystems/subsystems.hpp"
#include "turn.hpp"

Autonomous::Autonomous() {
	AddSequential(new Drive_Straight(1222 * 2, 0.4));
}
