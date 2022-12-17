#include "main.h"
#include "selection.h"
#include "globals.hpp"

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

void drivetrainMove(int voltage) {
	frontLeft.move_voltage(voltage);
	backLeft.move_voltage(voltage);
	frontRight.move_voltage(voltage);
	backRight.move_voltage(voltage);
}

void drivetrainBrake() {
	frontLeft.brake();
	backLeft.brake();
	frontRight.brake();
	backRight.brake();
}

void rollers(int minHue, int maxHue) {
	roller.move_voltage(12000);

	drivetrainMove(3000);
	pros::delay(2000);
	drivetrainBrake();

	while(!(rollerColour.get_hue() < minHue) && rollerColour.get_hue() <= maxHue) {
    	roller.brake();
	}


}

void autonomous() {
    

    /* ADD THE FOLLOWING TO YOUR AUTONOMOUS FUNTION IN MAIN.CPP */
    switch (autonSelection) {
		case RED_1:
			rollers(160, 260);
			break;
		case BLUE_1:
			rollers(0, 30);
			break;

		case RED_2:
            rollers(160, 260);
			break;
		case BLUE_2:
            rollers(0, 30);
			break;
			
		case RED_3:
			rollers(160, 260);
			break;
		case BLUE_3:
			rollers(0, 30);
			break;
			
		case RED_4:
			break;
		case BLUE_4:
			break;
			
		case RED_5:
			break;
		case BLUE_5:
			break;
			
		case SKILLS:
			rollers(0, 30);
			break;
	}
}

160 - 250 blue roller
000 - 030 red roller