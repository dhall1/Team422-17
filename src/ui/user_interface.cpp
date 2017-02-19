#include "user_interface.hpp"

#include "../commands/change_shooter_speed.hpp"
#include "../commands/set_gear_intake.hpp"
#include "../commands/prepare_shooter.hpp"
#include "../commands/lift_command.hpp"

Attack_3 *UI::left_joystick = nullptr;
Attack_3 *UI::right_joystick = nullptr;
//Launchpad *UI::launchpad = nullptr;
Xbox_Controller *UI::controller = nullptr;

void UI::initialize() {
	left_joystick = new Attack_3(3);
	right_joystick = new Attack_3(2);
//	launchpad = new Launchpad(1);
	controller = new Xbox_Controller(0);

	left_joystick->TRIGGER->WhenPressed(new Change_Shooter_Speed(true, 0, 0));
	left_joystick->BUTTON_2->WhenPressed(new Change_Shooter_Speed(false, 0, -1));
	left_joystick->BUTTON_3->WhenPressed(new Change_Shooter_Speed(false, 0, 1));
	left_joystick->BUTTON_4->WhenPressed(new Change_Shooter_Speed(false, 0, -0.5));
	left_joystick->BUTTON_5->WhenPressed(new Change_Shooter_Speed(false, 0, 0.5));

	right_joystick->TRIGGER->WhenPressed(new Change_Shooter_Speed(true, 1, 0));
	right_joystick->BUTTON_2->WhenPressed(new Change_Shooter_Speed(false, 1, -1));
	right_joystick->BUTTON_3->WhenPressed(new Change_Shooter_Speed(false, 1, 1));
	right_joystick->BUTTON_4->WhenPressed(new Change_Shooter_Speed(false, 1, -0.5));
	right_joystick->BUTTON_5->WhenPressed(new Change_Shooter_Speed(false, 1, 0.5));

	controller->B->WhenPressed(new Set_Gear_Intake(DoubleSolenoid::Value::kForward));
	controller->A->WhenPressed(new Set_Gear_Intake(DoubleSolenoid::Value::kReverse));
	controller->Y->WhenPressed(new Lift_Command(true));
	controller->X->WhenPressed(new Lift_Command(false));

	controller->RIGHT_BUMPER->WhenPressed(new Prepare_Shooter(true));
	controller->LEFT_BUMPER->WhenPressed(new Prepare_Shooter(false));
}
