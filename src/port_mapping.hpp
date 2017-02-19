#pragma once

namespace Ports {

	namespace CANBusIds {
		// Ids for CANTalons on Drive Base
		const uint32_t	LEFT_FRONT_MOTOR = 42,
						LEFT_MIDDLE_MOTOR = 46,
						LEFT_REAR_MOTOR = 41,
						RIGHT_FRONT_MOTOR = 39,
						RIGHT_MIDDLE_MOTOR = 43,
						RIGHT_REAR_MOTOR = 44;
		// Ids for CANTalons on Shooter
		const uint32_t	SHOOTER_TOP = 38, // 6
						SHOOTER_BOTTOM = 6; //38
		// Ids for CANTalons on Lift
		const uint32_t	LIFT_MOTOR = 45; // 45
		const uint32_t	INTAKE_MOTOR = 40; // 40
	}

	namespace Relays {
		const uint32_t COMPRESSOR_NODE = 0;
	}

	namespace Solenoids {
		const uint32_t	GEAR_INTAKE_FORWARD = 0,
						GEAR_INTAKE_REVERSE = 7,
						BALL_INTAKE_FORWARD = 1,
						BALL_INTAKE_REVERSE = 6;
	}

}


