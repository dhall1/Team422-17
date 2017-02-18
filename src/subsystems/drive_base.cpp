#include "drive_base.hpp"

#include "../commands/tank_drive.hpp"
#include "../port_mapping.hpp"

Drive_Base::Drive_Base() :
Subsystem ("Drive_Base"),
left_front_motor (new CANTalon(Ports::CANBusIds::LEFT_FRONT_MOTOR)),
left_middle_motor (new CANTalon(Ports::CANBusIds::LEFT_MIDDLE_MOTOR)),
left_rear_motor (new CANTalon(Ports::CANBusIds::LEFT_REAR_MOTOR)),
right_front_motor (new CANTalon(Ports::CANBusIds::RIGHT_FRONT_MOTOR)),
right_middle_motor (new CANTalon(Ports::CANBusIds::RIGHT_MIDDLE_MOTOR)),
right_rear_motor (new CANTalon(Ports::CANBusIds::RIGHT_REAR_MOTOR)) {

	// Front and Rear motors set to slave motors
//	left_front_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
//	left_front_motor->Set(Ports::CANBusIds::LEFT_MIDDLE_MOTOR);
//	left_rear_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
//	left_rear_motor->Set(Ports::CANBusIds::LEFT_MIDDLE_MOTOR);
//	right_front_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
//	right_front_motor->Set(Ports::CANBusIds::RIGHT_MIDDLE_MOTOR);
//	right_rear_motor->SetTalonControlMode(CANTalon::TalonControlMode::kFollowerMode);
//	right_rear_motor->Set(Ports::CANBusIds::RIGHT_MIDDLE_MOTOR);
	// Middle motor set to master motor
	left_front_motor->Set(0);
	left_middle_motor->Set(0);
	left_rear_motor->Set(0);
	right_front_motor->Set(0);
	right_middle_motor->Set(0);
	right_rear_motor->Set(0);
}

void Drive_Base::InitDefaultCommand() {
	SetDefaultCommand(new Tank_Drive());
}

void Drive_Base::set_motors_normalized(float left, float right) {
	left = -constrain(left) / 2;
	right = constrain(right) / 2;
	left_front_motor->Set(left);
	left_middle_motor->Set(left);
	left_rear_motor->Set(left);
	right_front_motor->Set(right);
	right_middle_motor->Set(right);
	right_rear_motor->Set(right);
}

float Drive_Base::constrain(float input) {
	if (input > 0.85) {
		return 0.85;
	} else if (input < -0.85) {
		return -0.85;
	}
	return input;
}
