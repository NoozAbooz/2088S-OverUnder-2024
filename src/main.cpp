#include "main.h"

int driveMode = 1;

void opcontrol() {
	while (true) {
    	if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
      		if(driveMode == 1){
        		driveMode = 0;
        		controller.rumble(".");
				controller.set_text(0, 0, "Drive DISABLED");
				pros::delay(50);
      		} else if(driveMode == 0) {
        		driveMode = 1;
        		controller.rumble("-");
				controller.set_text(0, 0, "DRIVE ENABLED");
				pros::delay(50);
      		}
    	}

		// Drive
		if(driveMode == 1){
    		int power = controller.get_analog(ANALOG_LEFT_Y);
    		int turn = controller.get_analog(ANALOG_RIGHT_X);
    		int left = (power - turn) * ((12000 / 127) / 1.2);
    		int right = (power + turn) * ((12000 / 127) / 1.2);
    		frontLeft.move_voltage(left);
			backLeft.move_voltage(left);
    		frontRight.move_voltage(right);
			backRight.move_voltage(right);

			// Individual button code
      		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
      			intake.move_voltage(12000);
			} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
			    intake.brake();
			}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
      			intake.move_voltage(-12000);
			} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			    intake.brake();
			}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      			flywheel.move_voltage(12000);
			} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
				flywheel.brake();
      		}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      			flywheel.move_voltage(-12000);
			} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
				flywheel.brake();
      		}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
      			roller.move_voltage(12000);
			} else {
			    roller.brake();
			}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      			roller.move_voltage(-12000);
			} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
				roller.brake();
      		}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
      			expansion.move_voltage(12000);
			} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
				expansion.brake();
      		}

			if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
      			expansion.move_voltage(-12000);
			} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
				expansion.brake();
      		}
		}
  	}
}
