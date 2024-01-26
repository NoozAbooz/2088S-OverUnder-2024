#include "abstractGlobals.hpp"
#include "api.h"
#include "deviceGlobals.hpp"
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
tailPiston.set_value(true);
chassis.moveToPoint(15.099, -48.739, 1000, false);
tailPiston.set_value(false);
chassis.moveToPoint(31.537, -49.503, 1000, false);
chassis.moveToPoint(15.099, -41.667, 1500);
chassis.moveToPoint(32.875, -45.68, 1500);
intake.move_voltage(-12000);
chassis.moveToPoint(16.055, -46.063, 1000, false);
intake.move_voltage(0);
chassis.moveToPoint(23.318, -17.966, 1000);
intake.move_voltage(12000);
chassis.moveToPoint(33.448, 2.867, 1000);
intake.move_voltage(-12000);
chassis.moveToPoint(43.005, -13.188, 1000);
intake.move_voltage(12000);
chassis.moveToPoint(59.06, 5.734, 1000);
chassis.moveToPoint(59.251, -4.969, 1000);
moveWings(true);
intake.move_voltage(-12000);
chassis.moveToPoint(58.869, -33.257, 1000);
chassis.moveToPoint(59.251, -20.969, 1000);
chassis.moveToPoint(58.869, -33.257, 1000);
chassis.moveToPoint(59.251, -20.969, 1000);
intake.move_voltage(0);
moveWings(false);

}

    if(selector::auton == 3){ //run auton for Back Red
chassis.moveToPoint(0, 0, 1500);
chassis.moveToPoint(11.963, 59.815, 1500);
chassis.moveToPoint(-5.982, 60.021, 1500);
chassis.moveToPoint(18.976, 34.239, 1500);
chassis.moveToPoint(-20.213, 23.514, 1500);

chassis.moveToPoint(-5.569, 2.475, 1500, false);
chassis.moveToPoint(24.545, 2.681, 1500, false);

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
        chassis.moveToPoint(-21.598, 16.628, 1500);
        chassis.moveToPoint(-21.024, 37.462, 1500);
        chassis.moveToPoint(-18.922, 7.454, 1500);
        chassis.moveToPoint(-15.482, 10.13, 1500);
        slapper.move_voltage(12000);
        //pros::delay(1000);
        pros::delay(40000);
        slapper.move_voltage(0);
        
        chassis.moveToPoint(7.454, 3.44, 1500);
        chassis.moveToPoint(37.271, 3.058, 1500);
        chassis.moveToPoint(42.813, 3.44, 1500);
        chassis.moveToPoint(73.394, 3.44, 1500);
        chassis.moveToPoint(66.705, 26.95, 1500);
        chassis.moveToPoint(43.196, 32.492, 1500);
        moveWings(true);
        chassis.moveToPoint(84.48, 47.783, 1500);
        moveWings(false);
        chassis.moveToPoint(43.769, 60.206, 1500);
        moveWings(true);
        chassis.moveToPoint(84.862, 60.589, 1500);
        moveWings(false);
        chassis.moveToPoint(44.916, 70.145, 1500);
        chassis.moveToPoint(43.387, 88.494, 1500);
        moveWings(true);
        chassis.moveToPoint(83.524, 75.306, 1500);
        moveWings(false);
        chassis.moveToPoint(65.558, 88.303, 1500);
        chassis.moveToPoint(68.043, 102.446, 1500);
        chassis.moveToPoint(97.095, 105.122, 1500);
        moveWings(true);
        chassis.moveToPoint(97.286, 86.009, 1500);
        moveWings(false);
        chassis.moveToPoint(89.45, 99.006, 1500);
        chassis.moveToPoint(48.739, 98.242, 1500);
        chassis.moveToPoint(57.339, 30.008, 1500);
        chassis.moveToPoint(95.948, 18.349, 1500);
        moveWings(true);
        chassis.moveToPoint(96.904, 37.462, 1500);   
        moveWings(false);


}

if (selector::auton == 5) { //run auton for testing pruportes
chassis.moveToPoint(0, 0, 1500);
intake.move_voltage(12000);
chassis.moveToPoint(0, 2.982, 1500);
chassis.moveToPoint(1.031, -32.176, 1000, false);
chassis.moveToPoint(15.469, -51.565, 1000, false);
tailPiston.set_value(true);
chassis.moveToPoint(30.239, -45.565, 1500, false);
tailPiston.set_value(false);
intake.move_voltage(0);
chassis.moveToPoint(16.501, -53.834, 1500);
chassis.moveToPoint(35.526, -55.69, 1500);

chassis.moveToPoint(16.913, -32.589, 1000, false);
chassis.moveToPoint(39.683, .4, 1000);
intake.move_voltage(12000);
pros::delay(1500);
chassis.moveToPoint(60.403, -12.994, 1500);
chassis.moveToPoint(60.228, -24.952, 1500);
moveWings(true);
intake.move_voltage(0);
chassis.moveToPoint(60.228, -39.952, 1500);
pros::delay(1000);
moveWings(false);
chassis.moveToPoint(62.259, -1.681, 1500);
intake.move_voltage(12000);
chassis.moveToPoint(62.64, -39.189, 1500);
chassis.moveToPoint(62.64, -20, 1000, false);
}
}