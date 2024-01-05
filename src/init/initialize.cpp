#include "main.h"

// Robodash GUI setup
rd::Selector selector({
{"Plow 1 Triball", &far_1tri},
{"Skills", &skills}
});

rd::Image logo("/usd/logo.bin", "Logo");
rd::Console console;

/**
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    console.clear();
    console.println("Robodash is running");
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System. This is intended for competition-specific initialization
 * routines, such as an autonomous selector on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    moveWings(false);
}

/**
 * Runs while the robot is in the disabled state of Field Management System 
 * following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    //leftLED.clear();
}