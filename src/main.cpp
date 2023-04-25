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
	bodyLED.set_all(0x0000FF);
	bodyLED.update();
  
  //-- Render funny gif on screen //--
  lv_obj_clean(lv_scr_act());
  lv_obj_t* obj = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj, 540, 300);
  lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 30, 30);
  Gif gif("/usd/gif/logo.gif", obj);

  while (true) {
    //-- Main drive code - Split Arcade Format //--
    int power = controller.get_analog(ANALOG_LEFT_Y);
    int turn = controller.get_analog(ANALOG_RIGHT_X);
    int left = (power + turn) * (12000 / 127);
    int right = (power - turn) * (12000 / 127);
    leftSide.move_voltage(left);
    rightSide.move_voltage(right);

    //-- Subsystem controls //--
    // Intake/Roller
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intake.move_voltage(10000);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intake.move_voltage(-10000);
    } else {
      intake.move_voltage(0);
    }

    // Catapult
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      fireCatapult();
      loadCatapult();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      loadCatapult();
    }

    // Expansion
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
				expansion.move_voltage(8000);
				pros::delay(800);
				expansion.brake();

        bodyLED.set_all(0xf1cbff);
    } else {
      expansion.brake();
    }

    //-- Print debug info to controller //--
    int cataValue = cataPosition.get_value();
    controller.print(1, 0, "%.0f°C %.0f°C %.0f°C      ", frontLeft.get_temperature(), catapultLeft.get_temperature(), intake.get_temperature());

    // Delay to prevent overloading brain :)
    pros::delay(10);
  }
}
