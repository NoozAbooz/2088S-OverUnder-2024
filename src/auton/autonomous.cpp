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

void drivetrainMove(int voltage, int time) {
	leftDrive.move_voltage(voltage);
	rightDrive.move_voltage(voltage);

	pros::delay(time);

	leftDrive.move_voltage(0);
	rightDrive.move_voltage(0);
}

void autonomous() {
    chassis.calibrate();
    if(selector::auton == 1){ //run auton for Front Red 

chassis.moveToPoint(0, 0, 5000);
chassis.moveToPoint(-1.65, -37.539, 5000);
chassis.moveToPoint(12.994, -54.865, 5000);
chassis.moveToPoint(33.001, -54.659, 5000);
chassis.moveToPoint(19.801, -45.171, 5000);
chassis.moveToPoint(34.033, -4.125, 5000);
chassis.moveToPoint(42.077, -11.138, 5000);
chassis.moveToPoint(57.546, 0.413, 5000);
chassis.moveToPoint(58.165, -39.395, 5000);
    }

    if(selector::auton == 2){ //run auton for Back Red
chassis.moveToPoint(0, 0, 5000);
chassis.moveToPoint(11.963, 59.815, 5000);
chassis.moveToPoint(-5.982, 60.021, 5000);
chassis.moveToPoint(18.976, 34.239, 5000);
chassis.moveToPoint(-20.213, 23.514, 5000);

chassis.moveToPoint(-5.569, 2.475, 5000, false);
chassis.moveToPoint(24.545, 2.681, 5000, false);


    }

    if(selector::auton == 0){ // skills
        slapper.move_voltage(12000);
        //pros::delay(1000);
        pros::delay(40000);
        slapper.move_voltage(0);
        
        drivetrainMove(12000, 3000);

        moveWings(true);

        drivetrainMove(12000, 2000);
        //chassis.MoveToPoint(0, 0, 60000);
//chassis.MoveToPoint(-15.291, 41.093, 60000);
//match load
//chassis.MoveToPoint(-20.642, 18.157, 60000);
//chassis.MoveToPoint(-9.939, 9.939, 60000);
//chassis.MoveToPoint(13.953, 10.703, 60000);
//chassis.MoveToPoint(43.769, 10.512, 60000);
//chassis.MoveToPoint(71.674, 10.13, 60000);
//chassis.MoveToPoint(88.303, 9.748, 60000);
//chassis.MoveToPoint(95.375, 9.557, 60000);
//chassis.MoveToPoint(99.962, 40.902, 60000);
//chassis.MoveToPoint(94.419, 30.581, 60000);
//chassis.MoveToPoint(72.057, 29.817, 60000);
//chassis.MoveToPoint(49.312, 34.213, 60000);
//chassis.MoveToPoint(65.94, 46.063, 60000);
//chassis.MoveToPoint(85.245, 51.606, 60000);
//chassis.MoveToPoint(50.841, 61.735, 60000);
//chassis.MoveToPoint(84.098, 65.558, 60000);
//chassis.MoveToPoint(48.93, 97.286, 60000);
//chassis.MoveToPoint(81.804, 80.275, 60000);
//chassis.MoveToPoint(80.275, 109.327, 60000);
//chassis.MoveToPoint(103.211, 94.801, 60000);
    }
}