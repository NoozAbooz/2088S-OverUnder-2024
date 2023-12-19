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

  pros::Task flashLED{[=] {
    while (true) {
      bodyLED.set_all(0x0000FF);
      bodyLED.update();
      pros::delay(500);
      bodyLED.set_all(0x000000);
      bodyLED.update();
      pros::delay(500);
    }
  }};
  
  //-- Render funny gif on screen //--
  // lv_obj_clean(lv_scr_act());
  // lv_obj_t* obj = lv_obj_create(lv_scr_act(), NULL);
  // lv_obj_set_size(obj, 540, 300);
  // lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 30, 30);
  // Gif gif("/usd/gif/logo.gif", obj);

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
      intake.move_voltage(12000);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      intake.move_voltage(-11000);
    } else {
      intake.move_voltage(0);
    }

    //-- Print debug info to controller //--
    controller.print(1, 0, "%.0f°C %.0f°C %.0f°C      ", intake.get_temperature());

    // Delay to prevent overloading brain :)
    pros::delay(10);
  }
}
