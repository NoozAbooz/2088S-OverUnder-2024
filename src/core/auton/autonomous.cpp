/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Main auton routine. Different autons are selected via the auton selector.
 */

#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

ASSET(example_txt);

void autonomous() {
    chassis.follow(example_txt, 15, 4000, false);
}

//void autonomous() {
//	chassis.setPose(0, 0, 0);
//	chassis.moveTo(0, 5, 5000, 50);
//}	

