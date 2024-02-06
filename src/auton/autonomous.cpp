#include "abstractGlobals.hpp"
#include "deviceGlobals.hpp"
#include "main.h"
#include "pros/rtos.hpp"

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

void drivetrainMove(int voltage, int time) {
	leftDrive.move_voltage(voltage);
	rightDrive.move_voltage(voltage);

	pros::delay(time);

	leftDrive.move_voltage(0);
	rightDrive.move_voltage(0);
}

void autonomous() {
    if(selector::auton == 2){ //run auton for Far Side 6 Triball NOAWP 

chassis.moveToPoint(0, 0, 1500);
intake.move_voltage(12000);
chassis.moveToPoint(-0.382, 3.645, 1000);
chassis.moveToPoint(-2.294, -25.229, 1000, false);
chassis.moveToPoint(-1.147, -33.066, 1000, false);
chassis.moveToPoint(15.099, -48.739, 1000, false);
tailPiston.set_value(false);
chassis.moveToPoint(31.537, -49.503, 1000, false);
tailPiston.set_value(true);
chassis.moveToPoint(15.099, -46.667, 1500);
chassis.moveToPoint(32.875, -46.68, 1500);
chassis.moveToPoint(16.055, -46.063, 1000, false);
intake.move_voltage(-12000);
chassis.moveToPoint(23.318, -30.966, 1000);
intake.move_voltage(12000);
chassis.moveToPoint(33.448, 2.867, 1000);
intake.move_voltage(-12000);
chassis.moveToPoint(43.005, -13.188, 1000);
intake.move_voltage(12000);
chassis.moveToPoint(59.06, 5.734, 1000);
chassis.moveToPoint(59.251, -4.969, 1000);

intake.move_voltage(-12000);
chassis.moveToPoint(58.869, -33.257, 1000);
chassis.moveToPoint(59.251, -20.969, 1000);
chassis.moveToPoint(58.869, -33.257, 1000);
chassis.moveToPoint(59.251, -20.969, 1000);
intake.move_voltage(0);

}

    if(selector::auton == 3){ //Close Side (1 scored)
//chassis.calibrate();

pros::delay(1000);

pros::delay(1000);

chassis.moveToPoint(0, 0, 1500);
tailPiston.set_value(false);
pros::delay(600);
chassis.turnTo(-10, 0, 5000, true, 100);
pros::delay(600);
tailPiston.set_value(true);

chassis.moveToPoint(15.057, 18.738, 1500, false);
chassis.moveToPoint(51.521, 10.238, 1500, false);

pros::delay(2000);
tailPiston.set_value(false);

drivetrainMove(-12000, 10000);

    }

    if(selector::auton == 4){ //NOT FRONT BLUE NEW AUTON WP THING THAT MAY OR MAY NOT WORK
chassis.moveToPoint(0, 0, 1500);
chassis.moveToPoint(0, 21.98, 1500);
chassis.moveToPoint(13.188, 35.359, 1500);
intake.move_voltage(12000);
pros::delay(1000);
intake.move_voltage(0);
chassis.moveToPoint(13.188, 50.268, 1500, false);
chassis.moveToPoint(13.761, 21.024, 1500, false);
chassis.moveToPoint(-2.485, -4.969, 1500, false);
chassis.moveToPoint(-22.171, 12.997, 1500, false);
chassis.moveToPoint(-22.554, 32.875, 1500, false);
chassis.moveToPoint(-24.847, 13.57, 1500, false);
//descore down
chassis.moveToPoint(-3.823, -4.587, 1500, false);
//descore up
chassis.moveToPoint(28.479, -3.058, 1500, false);


    }

    if(selector::auton == 1){ // skills
    chassis.moveToPoint(0, 0, 1500);
chassis.moveToPoint(-4.734, -21.999, 1500, false);
chassis.moveToPoint(-7.519, -17.544, 1500);
chassis.moveToPoint(-31.138, -24.227, 1500);
chassis.moveToPoint(-14.759, -9.747, 1500);
chassis.moveToPoint(-3.557, -2.506, 1500);
chassis.moveToPoint(-6, 28.683, 1500);
chassis.moveToPoint(-4.835, 73.796, 1500);
chassis.moveToPoint(-32.303, 94.403, 1500);
chassis.moveToPoint(-11.974, 94.681, 1500, false);
chassis.moveToPoint(-32.581, 94.681, 1500);
chassis.moveToPoint(-20.607, 76.302, 1500, false);
chassis.moveToPoint(-26.733, 42.606, 1500);
chassis.moveToPoint(-44.834, 81.036, 1500, false);
chassis.moveToPoint(-31.468, 59.593, 1500);
chassis.moveToPoint(-44.556, 80.757, 1500);
chassis.moveToPoint(-54.024, 39.543, 1500, false);
chassis.moveToPoint(-59.315, 82.707, 1500);
chassis.moveToPoint(-64.884, 58.758, 1500, false);
chassis.moveToPoint(-59.036, 80.757, 1500);
chassis.moveToPoint(-81.314, 40.379, 1500, false);
chassis.moveToPoint(-69.618, 80.479, 1500);
chassis.moveToPoint(-92.732, 52.075, 1500, false);
chassis.moveToPoint(-95.795, 71.846, 1500);
chassis.moveToPoint(-111.668, 79.365, 1500, false);
chassis.moveToPoint(-108.048, 91.339, 1500,false);
chassis.moveToPoint(-81.871, 91.618, 1500, false);
chassis.moveToPoint(-99.415, 96.63, 1500);
chassis.moveToPoint(-82.15, 98.301, 1500, false);

}

if (selector::auton == 5) { //run auton for testing pruportes
chassis.moveToPoint(0, 0, 1500);
intake.move_voltage(12000);
chassis.moveToPoint(0, 2.982, 1500);
chassis.moveToPoint(1.031, -33.176, 1000, false);
chassis.moveToPoint(15.469, -51.565, 1000, false, 40);
tailPiston.set_value(false);
chassis.moveToPoint(30.239, -42.565, 1500, false);
tailPiston.set_value(true);
chassis.moveToPoint(16.501, -53.834, 1500, false, 127);
chassis.moveToPoint(39.526, -55.69, 1000);
intake.move_voltage(-12000);

chassis.moveToPoint(21.913, -32.589, 1000, false);
intake.move_voltage(0);
chassis.moveToPoint(39.683, 2.4, 1000);
intake.move_voltage(12000);
pros::delay(1500);
chassis.moveToPoint(57.403, -12.994, 1500);
chassis.moveToPoint(56.228, -24.952, 1000);

intake.move_voltage(-12000);
chassis.moveToPoint(58.228, -41.952, 1000);
pros::delay(1000);
intake.move_voltage(0);

chassis.moveToPoint(58.259, -1.181, 1500);
intake.move_voltage(12000);
chassis.moveToPoint(55.64, -42.189, 1500);
chassis.moveToPoint(50.64, -22, 1000, false);
}

if (selector::auton == 6) { //testing skills
        slapper.move_voltage(10000);
        //pros::delay(1000);
        pros::delay(40000);
        slapper.move_voltage(0);

        drivetrainMove(12000, 3000);

        drivetrainMove(12000, 2000);
}

}