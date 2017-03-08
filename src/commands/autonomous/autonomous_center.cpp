#include "autonomous_center.hpp"

#include "drive_straight.hpp"

Autonomous_Center::Autonomous_Center() {
	AddSequential(new Drive_Straight(3424));
}
