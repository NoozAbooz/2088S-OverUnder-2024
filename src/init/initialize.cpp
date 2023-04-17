/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Extra code that runs on robot init (mainly auton selector)
 */

#include "main.h"
#include "pros/rtos.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // Init LEDs
    bodyLED.set_all(0xda8d53);
    bodyLED.update();

    // Calibrate chassis inertial sensor
    pros::Task task{[=] {
        chassis.calibrate();
    }};

    // Setup Cata
    loadCatapult();

    // Initialize the auton selector screen on brain LCD
    selectorInit();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    bodyLED.clear();
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    // Initialize the auton selector on brain LCD
    selectorInit();
}