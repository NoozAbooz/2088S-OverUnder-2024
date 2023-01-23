#include "main.h"

void opcontrol() {
	bool intakeSwitch = false;

	while(true) {
		// Drive code
    	int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power - turn) * (12000 / 127);
    	int right = (power + turn) * (12000 / 127);
    	frontLeft.move_voltage(left);
		backLeft.move_voltage(left);
    	frontRight.move_voltage(right);
		backRight.move_voltage(right);

		// Subsystem trigger
     	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2 or intakeSwitch == true)) {
      		intake.brake();
		} else {
		   intake.move_voltage(12000);
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      		intake.move_voltage(-12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		    intake.brake();
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		flywheel.move_voltage(12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			flywheel.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      		flywheel.move_voltage(-12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			flywheel.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      		roller.move_voltage(6000);
		} else {
		    roller.brake();
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      		roller.move_voltage(-6000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
			roller.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      		expansion.move_voltage(12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			expansion.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      		expansion.move_voltage(-12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			expansion.brake();
      	}

		// bind shoot func
		
		controller.print(1, 0, "Speed: %lf | Temp: %dC", motorSpeed, flywheelTemp);
		pros::delay(10);
  	}
}
