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

/** THE GREAT AUTON INDEX  **/
// 0: Do nothing
// 6: Skills (run kicker only and simple movements to goal)

// 2: NORUSH 6-ball far side start with preload under alley
// 3: AWP close side descore and touch bar

void autonomous() {
    if(selector::auton == 2){ //run auton for Far Side 6 Triball NORUSH

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

    if(selector::auton == 3){ //Close Side AWP no triball literally just descore and touch bar
//chassis.calibrate();

pros::delay(1000);

pros::delay(1000);

chassis.moveToPoint(0, 0, 1500);
tailPiston.set_value(false);
pros::delay(600);
chassis.turnTo(-10, 0, 1000, true, 100);
pros::delay(600);
tailPiston.set_value(true);

chassis.moveToPoint(15.057, 18.738, 1500, false);
chassis.moveToPoint(51.521, 10.238, 1500, false);

pros::delay(2000);
tailPiston.set_value(false);

drivetrainMove(-12000, 10000);

    }

    if(selector::auton == 4){


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
    pros::delay(45000);
    slapper.move_voltage(0);

    chassis.moveToPoint(0, 0, 1500);
    chassis.moveToPoint(24.969, 24.772, 2000);
    chassis.moveToPoint(25.952, 54.853, 2000);
    chassis.moveToPoint(109.705, 56.622, 3000);

    drivetrainMove(-12000, 1000);
    wingsPiston.set_value(true);
    drivetrainMove(12000, 1500);
    drivetrainMove(-12000, 1000);
    drivetrainMove(12000, 3000);
}

if (selector::auton == 7) { //rush auton w path.jerryio
chassis.moveToPoint(0, 0, 500);
chassis.moveToPoint(2.939, 65.648, 1000);
intake.move_voltage(12000);
chassis.moveToPoint(9.104, 64.967, 500);
wingsPiston.set_value(true);
pros::delay(500);
chassis.moveToPoint(34.117, 44.228, 1000);
intake.move_voltage(-12000);
chassis.moveToPoint(23.283, 53.319, 1000, false);
intake.move_voltage(0);
chassis.moveToPoint(34.287, 43.835, 1000);
wingsPiston.set_value(false);
pros::delay(500);
chassis.moveToPoint(12.591, 46.821, 1000, false);
chassis.moveToPoint(-6.186, 52.097, 1000);
intake.move_voltage(12000);
chassis.moveToPoint(-4.547, 30.263, 1000);
chassis.moveToPoint(1.857, 20.648, 1000);
intake.move_voltage(-12000);
pros::delay(500);
chassis.moveToPoint(-11.681, 4.812, 1000);
intake.move_voltage(0);
chassis.moveToPoint(-34.376, 23.855, 1000);
intake.move_voltage(12000);
chassis.moveToPoint(-6.293, -0.958, 1000, false);
tailPiston.set_value(false);
pros::delay(500);
chassis.moveToPoint(14.418, 1.126, 1000, false, 45);
tailPiston.set_value(true);
pros::delay(500);
chassis.moveToPoint(27.378, 12.706, 1000, false, 127);
chassis.moveToPoint(16.567, -0.179, 1000);
chassis.moveToPoint(26.921, 14.837, 1000, false);
chassis.moveToPoint(16.567, -0.179, 1000);
chassis.moveToPoint(26.921, 14.837, 1000, false);

}
if (selector::auton == 8) { // skills auton with hang

slapper.move_voltage(12000);
pros::delay(31000);
chassis.moveToPoint(0, 0, 1000);
chassis.moveToPoint(-28.292, 12.577, 1000, false);
chassis.moveToPoint(-17.694, -1.61, 1000);
chassis.moveToPoint(6.374, 5.104, 1000);
chassis.moveToPoint(52.997, 73.022, 1000);
chassis.moveToPoint(52.562, 93.393, 1000);
chassis.moveToPoint(37.688, 103.808, 1000, false);
chassis.moveToPoint(41.13, 85.065, 1000);
chassis.moveToPoint(12.645, 63.711, 1000);
tailPiston.set_value(false);
pros::delay(500);
chassis.moveToPoint(19.289, 99.191, 1000, false);
tailPiston.set_value(true);
pros::delay(500);
chassis.moveToPoint(-9.996, 70.698, 1000);
tailPiston.set_value(false);
pros::delay(500);
chassis.moveToPoint(8.596, 106.912, 1000, false);
tailPiston.set_value(true);
pros::delay(500);  
chassis.moveToPoint(-27.655, 89.13, 1000);
tailPiston.set_value(false);
pros::delay(500);   
chassis.moveToPoint(0.783, 113.083, 1000, false);
tailPiston.set_value(true); 
pros::delay(500);
chassis.moveToPoint(-40.305, 101.721, 1000);
chassis.moveToPoint(-26.301, 143.714, 1000);
chassis.moveToPoint(-5.383, 135.6, 1000, false);
chassis.moveToPoint(-47.551, 132.693, 1000);
liftPiston.set_value(true);
pros::delay(500);
chassis.moveToPoint(-65.154, 107.22, 1000);
liftPiston.set_value(false);


}

if (selector::auton == 9) { //auton wp tester

chassis.moveToPoint(0, 0, 1000, false);
tailPiston.set_value(false);
pros::delay(500);
chassis.moveToPoint(4.689, -10.172, 1000);
tailPiston.set_value(true);
pros::delay(500);
chassis.moveToPoint(47.463, 25.045, 1000);
wingsPiston.set_value(true);
pros::delay(500);
chassis.moveToPoint(61.372, 13.374, 1000);
wingsPiston.set_value(false);
pros::delay(500);
chassis.moveToPoint(1.909, 21.602, 1000);
chassis.moveToPoint(12.545, 33.386, 1000);
chassis.moveToPoint(7.472, 16.934, 1000, false);
chassis.moveToPoint(9.862, -7.277, 1000, false);
chassis.moveToPoint(29.798, -24.255, 1000, false);

}
}