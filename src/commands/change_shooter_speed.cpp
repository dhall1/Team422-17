#include "change_shooter_speed.hpp"

#include "../subsystems/subsystems.hpp"

/*
 * Mostly for testing purposes. During matches, a default speed should
 * be set for the entire match, most likely using PID and speed mode
 */
Change_Shooter_Speed::Change_Shooter_Speed(bool stop, int side, float direction) :
stop (stop),
side (side),
direction (direction) {
	Requires(Subsystems::shooter);
}
void Change_Shooter_Speed::Initialize() {
	if (side == 0) {
		// Bottom Motor
		if (stop)  {
			Subsystems::shooter->set_front_speed(0);
		} else {
			float speed = Subsystems::shooter->get_front_speed();
			speed += (direction * 0.1);
			Subsystems::shooter->set_front_speed(speed);
		}
	} else if (side == 1) {
		// Top Motor
		if (stop) {
			Subsystems::shooter->set_back_speed(0);
		} else {
			float speed = Subsystems::shooter->get_back_speed();
			speed += (direction * 0.1);
			Subsystems::shooter->set_back_speed(speed);
		}
	}
}

bool Change_Shooter_Speed::IsFinished() {
	return true;
}
