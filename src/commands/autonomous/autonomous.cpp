#include "autonomous.hpp"

#include "drive_straight.hpp"

Autonomous::Autonomous() {
	AddSequential(new Drive_Straight(10));
}
