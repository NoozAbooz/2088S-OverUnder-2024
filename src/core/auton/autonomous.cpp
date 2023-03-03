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

//void autonomous() {
//    switch (autonSelection) {
//		case RED_1: // Within auton starting line, facing rollers
//			// Move forward, spin rollers, move back
//			rollerAuton();
//
//			// Turn left 90 deg
//			drivetrainTurn(-1, 690);
//			// Drive into low goal
//			drivetrainMove(4000, 4000);
//
//			// Dispense discs
//			dispenseDiscs();
//			break;
//		case RED_2: // Outside auton starting line
//			// Navigate from starting line to roller
//            drivetrainMove(3000, 2100);
//			drivetrainTurn(1, 2000);
//			drivetrainMove(2000, 2000);
//
//			// Spin rollers
//			rollerAuton();
//
//			// Turn and drive into low goal
//			drivetrainMove(-2000, 500);
//			drivetrainTurn(1, 2000);
//			drivetrainMove(4000, 3200);
//
//			// Dispense discs
//			dispenseDiscs();
//			break;
//		case RED_3:
//			// Pure roller auton only
//			rollerAuton();
//			break;
//		case RED_4:
//			// Pure low goal dispense only
//			drivetrainMove(6000, 1000);
//
//			intake.move_voltage(-12000);
//			pros::delay(6000);
//			intake.brake();
//			break;
//
//		// Unused blue autons
//		case RED_5:
//			break;
//		case BLUE_1:
//			break;
//		case BLUE_2:
//			break;
//		case BLUE_3:
//			break;
//		case BLUE_4:
//			break;
//		case BLUE_5:
//			break;
//			
//		case SKILLS:
//			break;
//	}
//}