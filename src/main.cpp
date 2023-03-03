#include "main.h"
#include "pros/rtos.hpp"
#include <string>

void opcontrol() {
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

		// Intake
     	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		intake.move_voltage(12000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
	  		intake.move_voltage(-12000);
		} else {
		    intake.brake();
		}
		
		// Catapult
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		catapult.move_voltage(12000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			catapult.move_voltage(-12000);
		} else {
			catapult.brake();
      	}

		// Roller
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      		roller.move_voltage(5000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
			roller.move_voltage(-5000);
		} else {
		    roller.brake();
		}

		// Expansion
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      		expansion.move_voltage(7000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			expansion.move_voltage(-4000);
		} else {
			expansion.brake();
      	}
		
		controller.print(1, 0, "%.0f %.0f°C %.0f°C     ", cataStatus.get_value(), expansion.get_temperature(), frontLeft.get_temperature());

		pros::delay(10);
  	}
}