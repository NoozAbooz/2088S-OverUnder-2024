#include "abstractGlobals.hpp"
#include "deviceGlobals.hpp"
#include "main.h"

//ASSET(test_txt); // '.' replaced with "_" to make c++ happy

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
void autonomous() {
    close_wp();

    // // example movement: Move to x: 20 and y:15, and face heading 90. Timeout set to 4000 ms
    // chassis.moveTo(20, 15, 90, 4000);
    // // example movement: Turn to face the point x:45, y:-45. Timeout set to 1000
    // // dont turn faster than 60 (out of a maximum of 127)
    // chassis.turnTo(45, -45, 1000, true, 60);
    // // example movement: Follow the path in path.txt. Lookahead at 15, Timeout set to 4000
    // // following the path with the back of the robot (forwards = false)
    // // see line 110 to see how to define a path
    // chassis.follow(test_txt, 15, 4000, false);
    // // wait until the chassis has travelled 10 inches. Otherwise the code directly after
    // // the movement will run immediately
    // // Unless its another movement, in which case it will wait
    // chassis.waitUntil(10);
    // pros::lcd::print(4, "Travelled 10 inches during pure pursuit!");
    // // wait until the movement is done
    // chassis.waitUntil(1000000);
    // pros::lcd::print(4, "pure pursuit finished!");
}



void close_wp() {
    moveWings(true);

    leftDrive.move_voltage(-12000);
    rightDrive.move_voltage(-12000);

    pros::delay(3000);

    leftDrive.move_voltage(0);
    rightDrive.move_voltage(0);

    moveWings(false);
    intakePiston.extend();
}