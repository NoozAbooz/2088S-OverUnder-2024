/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Main auton routine. Different autons are selected via the auton selector.
 */

#include "declaration.hpp"
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

ASSET(test_txt);

void autonomous() {
    //chassis.calibrate();

    if(selector::auton == 1){ //run auton for Front Red 
        drivetrainMove(-12000, 4000);
        drivetrainMove(4000, 1000);
    }

    if(selector::auton == 2){ //run auton for Back Red
        chassis.arcade(-127, 0);

        pros::delay(4000);

        chassis.arcade(42, 0);

        pros::delay(1000);

        chassis.arcade(0, 0);
    }

    intake.move(127);
chassis.moveToPoint(0, 0, 5000);
chassis.moveToPoint(-17.075, 59.401, 5000);
chassis.moveToPoint(0.538, 49.532, 5000);
chassis.moveToPoint(-10.423, 50.34, 5000, false);
intake.move(-127);
chassis.moveToPoint(1.884, 50.34, 5000);



    //chassis.setPose(0, 0, 0);

}

//void autonomous() {
//	chassis.setPose(0, 0, 0);
//	chassis.moveToPoint(0, 5, 5000, 50);
//}	

void drivetrainMove(int voltage, int time) {
	leftDrive.move_voltage(voltage);
	rightDrive.move_voltage(voltage);

	pros::delay(time);

	leftDrive.move_voltage(0);
	rightDrive.move_voltage(0);
}