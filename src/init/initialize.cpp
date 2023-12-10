#include "abstractGlobals.hpp"
#include "deviceGlobals.hpp"
#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

rd::Selector selector;

void initialize() {
    intakePiston.extend();
    //loadCatapult();

    selector.add_autons({
        {"Plow Triball (1pt)", close_wp},
	    
    });

	selector.focus();

    // Render funny gif on screen
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
    moveWings(false);
    intakePiston.retract();
    loadCatapult();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    //leftLED.clear();
}