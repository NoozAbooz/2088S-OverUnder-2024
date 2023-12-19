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
    lemlib::Pose pose = chassis.getPose();
    controller.print(1, 0, "%.0f°C X:%f Y:%f Deg:%f", intake.get_temperature(), pose.x, pose.y, pose.theta);

    // Delay to prevent overloading brain :)
    pros::delay(10);
  }
}
