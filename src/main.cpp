/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Main opcontrol loop. Runs drivetrain as well as additional subsystems.
 */

#include "main.h"
#include "declaration.hpp"
#include "pros/rtos.hpp"
#include <string>

void opcontrol() {
	//-- Render funny gif on screen //--
	//lv_obj_clean(lv_scr_act());
	//lv_obj_t* obj = lv_obj_create(lv_scr_act(), NULL);
	//lv_obj_set_size(obj, 500, 500);
	//lv_obj_set_style(obj, &lv_style_transp);
	//lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);
	//Gif gif("/usd/sus/logo.gif", obj);

	while(true) {
		//-- Main drive code - Split Arcade Format //--
    	int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power + turn) * (12000 / 127);
    	int right = (power - turn) * (12000 / 127);
    	leftSide.move_voltage(left);
		rightSide.move_voltage(right);

		//-- Subsystem controls //--
		// Intake/Roller
     	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		intake.move_voltage(12000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
	  		intake.move_voltage(-12000);
		} else {
		    intake.brake();
		}
		
		// Catapult
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			fireCatapult();
			loadCatapult();
      	}
		
		// Expansion
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			expansion.move_voltage(12000);
			pros::delay(1000);

			bodyLED.gradient(0x3e7690, 0xa0998e);
			bodyLED.cycle(*bodyLED, 10);
		} else {
			expansion.brake();
		}

		//-- Print debug info to controller //--
		double chassisTempAvg = getAverage(leftSide.get_temperatures());
		double catapultTempAvg = getAverage(catapult.get_temperatures());

		controller.print(1, 0, "%.0f°C %.0f°C %.0f     ", chassisTempAvg, catapultTempAvg, cataPosition.get_value());

		// Delay to prevent overloading brain :)
		pros::delay(10);
  	}
}
 