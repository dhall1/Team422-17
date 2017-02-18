#include "drive_straight.hpp"

Drive_Straight::Drive_Straight(float distance) :
ticks (distance_to_ticks(distance)) {

}

void Drive_Straight::Initialize() {

}

bool Drive_Straight::IsFinished() {
	return true;
}

float Drive_Straight::distance_to_ticks(float input) {
	// Assuming that input is distance in feet
	float inches = input / 12;
	// Distance / circumference = # of revolutions
	float revolutions = inches / (CIRCUMFERENCE);
	// 12 ticks per revolution
	float ticks = revolutions / TICK_PER_REVOLUTION;
	return ticks;
}
