#include "autonomous_baseline.hpp"

#include "drive_straight.hpp"

Autonomous_Baseline::Autonomous_Baseline() {
	AddSequential(new Drive_Straight(10000, 0.3, 3.5));
}
