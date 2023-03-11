/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Main opcontrol loop. Runs drivetrain as well as additional subsystems.
 * @date 2023-03-10
 */

#include "main.h"
#include "pros/rtos.hpp"
#include <string>

#include "gif-pros/gifclass.hpp"

void opcontrol() {
	//-- Render funny gif on screen //--
	lv_obj_t* obj = lv_obj_create(lv_scr_act(), NULL);
	lv_obj_set_size(obj, 185, 147);
	lv_obj_set_style(obj, &lv_style_transp);
	lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);
	Gif gif("/usd/sus.gif", obj);

	while(true) {
		//-- Main drive code //--
    	int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power + turn) * (12000 / 127);
    	int right = (power - turn) * (12000 / 127);
    	frontLeft.move_voltage(left);
		backLeft.move_voltage(left);
    	frontRight.move_voltage(right);
		backRight.move_voltage(right);

		//-- Subsystem controls //--

		// Intake/Roller
     	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		intake.move_voltage(12000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
	  		intake.move_voltage(-12000);
		} else {
		    intake.brake();
		}
		
		// Catapult/Expansion
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		catapult.move_voltage(6000);
		} else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			catapult.move_voltage(-10000);
		} else {
			catapult.brake();
      	}
		
		//-- Print debug info to controller //--
		controller.print(1, 0, "%.0f°C %.0f°C %.0f°C     ", catapult.get_temperature(), expansion.get_temperature(), frontLeft.get_temperature());

		pros::delay(10);
  	}
}
