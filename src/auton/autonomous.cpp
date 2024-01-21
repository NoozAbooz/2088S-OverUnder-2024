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
    if(selector::auton == 2){ //run auton for Front Red 

chassis.moveToPoint(0, 0, 5000);
intake.move_voltage(12000);
pros::delay(1000);
intake.move_voltage(0);
chassis.moveToPoint(-0.956, -41.284, 5000, false);
// descore down
chassis.moveToPoint(14.526, -57.339, 5000, false);
// descore up
chassis.moveToPoint(33.639, -57.913, 5000, false);
chassis.moveToPoint(14.144, -56.575, 5000);
chassis.moveToPoint(33.257, -57.531, 5000);
chassis.moveToPoint(15.291, -56.193, 5000);
chassis.moveToPoint(34.595, -3.823, 5000);
intake.move_voltage(12000);
pros::delay(1000);
intake.move_voltage(0);
chassis.moveToPoint(39.755, -7.836, 5000);
intake.move_voltage(-12000);
pros::delay(500);
intake.move_voltage(0);
chassis.moveToPoint(58.677, -2.676, 5000);
intake.move_voltage(12000);
pros::delay(1000);
intake.move_voltage(0);
chassis.moveToPoint(58.869, -10.703, 5000);
moveWings(true);
pros::delay(500);
chassis.moveToPoint(59.633, -42.431, 5000);
chassis.moveToPoint(58.869, -30.581, 5000);
chassis.moveToPoint(59.633, -42.431, 5000);
chassis.moveToPoint(58.869, -30.581, 5000);
moveWings(false);

}

    if(selector::auton == 3){ //run auton for Back Red
chassis.moveToPoint(0, 0, 5000);
chassis.moveToPoint(11.963, 59.815, 5000);
chassis.moveToPoint(-5.982, 60.021, 5000);
chassis.moveToPoint(18.976, 34.239, 5000);
chassis.moveToPoint(-20.213, 23.514, 5000);

chassis.moveToPoint(-5.569, 2.475, 5000, false);
chassis.moveToPoint(24.545, 2.681, 5000, false);

    }

    if(selector::auton == 4){ //NOT FRONT BLUE NEW AUTON WP THING THAT MAY OR MAY NOT WORK
chassis.moveToPoint(0, 0, 5000);
chassis.moveToPoint(0, 21.98, 5000);
chassis.moveToPoint(13.188, 35.359, 5000);
intake.move_voltage(12000);
pros::delay(1000);
intake.move_voltage(0);
chassis.moveToPoint(13.188, 50.268, 5000, false);
chassis.moveToPoint(13.761, 21.024, 5000, false);
chassis.moveToPoint(-2.485, -4.969, 5000, false);
chassis.moveToPoint(-22.171, 12.997, 5000, false);
chassis.moveToPoint(-22.554, 32.875, 5000, false);
chassis.moveToPoint(-24.847, 13.57, 5000, false);
//descore down
chassis.moveToPoint(-3.823, -4.587, 5000, false);
//descore up
chassis.moveToPoint(28.479, -3.058, 5000, false);


    }

    if(selector::auton == 1){ // skills
       
        chassis.moveToPoint(0, 0, 5000);
        chassis.moveToPoint(-21.598, 16.628, 5000);
        chassis.moveToPoint(-21.024, 37.462, 5000);
        chassis.moveToPoint(-18.922, 7.454, 5000);
        chassis.moveToPoint(-15.482, 10.13, 5000);
        slapper.move_voltage(12000);
        //pros::delay(1000);
        pros::delay(40000);
        slapper.move_voltage(0);
        
        chassis.moveToPoint(7.454, 3.44, 5000);
        chassis.moveToPoint(37.271, 3.058, 5000);
        chassis.moveToPoint(42.813, 3.44, 5000);
        chassis.moveToPoint(73.394, 3.44, 5000);
        chassis.moveToPoint(66.705, 26.95, 5000);
        chassis.moveToPoint(43.196, 32.492, 5000);
        moveWings(true);
        chassis.moveToPoint(84.48, 47.783, 5000);
        moveWings(false);
        chassis.moveToPoint(43.769, 60.206, 5000);
        moveWings(true);
        chassis.moveToPoint(84.862, 60.589, 5000);
        moveWings(false);
        chassis.moveToPoint(44.916, 70.145, 5000);
        chassis.moveToPoint(43.387, 88.494, 5000);
        moveWings(true);
        chassis.moveToPoint(83.524, 75.306, 5000);
        moveWings(false);
        chassis.moveToPoint(65.558, 88.303, 5000);
        chassis.moveToPoint(68.043, 102.446, 5000);
        chassis.moveToPoint(97.095, 105.122, 5000);
        moveWings(true);
        chassis.moveToPoint(97.286, 86.009, 5000);
        moveWings(false);
        chassis.moveToPoint(89.45, 99.006, 5000);
        chassis.moveToPoint(48.739, 98.242, 5000);
        chassis.moveToPoint(57.339, 30.008, 5000);
        chassis.moveToPoint(95.948, 18.349, 5000);
        moveWings(true);
        chassis.moveToPoint(96.904, 37.462, 5000);   
        moveWings(false);


}
}