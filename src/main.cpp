#include "main.h"

void opcontrol() {
	auto timeFlag=pros::millis();
	while(true) {
		if(pros::millis()-timeFlag>=1000) {
			controller.print(1, 0, "test");
            timeFlag=pros::millis();
        }
		
		// Drive
    	int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power - turn) * (12000 / 127);
    	int right = (power + turn) * (12000 / 127);
    	frontLeft.move_voltage(left);
		backLeft.move_voltage(left);
    	frontRight.move_voltage(right);
		backRight.move_voltage(right);

		// Individual button code
     	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		intake.move_voltage(12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		   intake.brake();
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
		
		pros::Task::delay_until(&timeFlag, 10);
  	}
}
