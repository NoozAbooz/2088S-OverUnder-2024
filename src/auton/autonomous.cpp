#include "deviceGlobals.hpp"
#include "main.h"
#include "pros/adi.hpp"

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

/** THE GREAT AUTON INDEX  **/
// 0: Do nothing
// 6: Skills (run kicker only and simple movements to goal)
// 7: new skills with push triball

// 3 new code
// 5: Push 1 triball with back
// 2: NORUSH 6-ball far side start with preload under alley
// 7: RUSH 6-ball

// 9: AWP close side descore and touch bar

// 4: Elims disrupt

using namespace strait;
void autonomous() {
    chassis.setPose(0,0,0);

    switch(selector::auton) {
        case 0: // Do nothing
            break;
        case 1: // Skills
            break;
        case 2: // far side rush 6-ball inception
            chassis.moveToPoint(0, 0, 1250);
            rightWingPiston.set_value(true);
            pros::delay(400);
            rightWingPiston.set_value(false);
            chassis.moveToPoint(-7.66, 46.342, 1250);
            intake.move_voltage(12000);
            pros::delay(200);
            intake.move_voltage(0);
            chassis.moveToPoint(0, 0, 1250);
            chassis.moveToPoint(7.511, -7.277, 750);
            intake.move_voltage(-12000);
            pros::delay(800);
            intake.move_voltage(12000);
            chassis.moveToPoint(-25.469, -8.043, 1250);
            chassis.moveToPoint(9.192, -6.128, 1000, {false, 127});
            intake.move_voltage(0);
            tailPiston.set_value(true);
            chassis.moveToPoint(26.618, 8.617, 1000, {false, 127});
            tailPiston.set_value(false);
            chassis.moveToPoint(26.043, 24.894, 1000, {false, 127});
            chassis.moveToPoint(23.277, 7.851, 750);
            rightWingPiston.set_value(true);    
            chassis.moveToPoint(23.66, 24.703, 1250);
            chassis.moveToPoint(19.341, 7.468, 1000, {false});
            rightWingPiston.set_value(false);
            intake.move_voltage(12000);
            chassis.moveToPoint(-25.086, 26.235, 1000);
            pros::delay(200);
            intake.move_voltage(0);
            chassis.moveToPoint(13.213, 39.065, 1000);
            chassis.moveToPoint(-16, 56.363, 500, {false});
            intake.move_voltage(12000);
            chassis.moveToPoint(-26.426, 56.363, 1000);
            leftWingPiston.set_value(true);
            rightWingPiston.set_value(true);
            chassis.moveToPoint(12.639, 56.938, 1250);
            chassis.moveToPoint(0.639, 56.938, 1000, {false});
            break;
        case 3: // close side awp disrupt
            chassis.moveToPoint(0, 0, 1000);
            chassis.moveToPoint(8.617, 45.576, 1000);
            chassis.moveToPoint(27.575, 45.959, 1000);
            chassis.moveToPoint(-13.022, -3.638, 1000);
            chassis.moveToPoint(-25.277, 25.66, 1000);
            chassis.moveToPoint(-27.767, 10.149, 1000);
            chassis.moveToPoint(-12.256, -6.319, 1000);
            chassis.moveToPoint(28.15, -5.936, 1000);
            chassis.moveToPoint(-18.383, 0.957, 1000);
            break;
        case 4: // close side awp bowl
            chassis.moveToPoint(0, 0, 1250);
            chassis.moveToPoint(-7.66, 46.342, 1250);
            chassis.moveToPoint(6.511, -7.277, 1250);
            chassis.moveToPoint(-25.469, -8.043, 1250);
            chassis.moveToPoint(9.192, -6.128, 1250);
            chassis.moveToPoint(26.618, 8.617, 1250);
            chassis.moveToPoint(26.043, 24.894, 1250);
            chassis.moveToPoint(25.277, 7.851, 1250);
            chassis.moveToPoint(25.66, 24.703, 1250);
            chassis.moveToPoint(19.341, 7.468, 1250);
            chassis.moveToPoint(-25.086, 26.235, 1250);
            chassis.moveToPoint(13.213, 39.065, 1250);
            chassis.moveToPoint(-26.426, 50.363, 1250);
            chassis.moveToPoint(12.639, 50.938, 1250);
            break;
        case 5: // old awp
            chassis.moveToPoint(0, 0, 1500);

            intake.move_voltage(-10000);
            pros::delay(200);
            intake.move_voltage(0);

            // leftWingPiston.set_value(true);
            // pros::delay(600);
            // leftWingPiston.set_value(false); //open wings for triball

            tailPiston.set_value(true);
            pros::delay(600);
            chassis.turnToHeading(-90, 1000);
            pros::delay(600);
            tailPiston.set_value(false); //descore turn -90deg
            chassis.turnToPoint(10, -100, 1000, {true, 110});
            chassis.turnToPoint(100, -20, 1000, {true, 110});

            //chassis.moveToPoint(0, 25.339, 1000, false);

            // chassis.moveToPoint(8, 28.738, 1500, false, 80);
            // chassis.moveToPoint(51.521, 10.238, 1500, false, 80);
            // pros::delay(2000);
            // tailPiston.set_value(false);
            // strait::moveRaw(-12000, 10000);
            leftWingPiston.set_value(true);
            rightWingPiston.set_value(true);

            chassis.moveToPoint(8.811, -8.277, 1500);
            chassis.moveToPoint(38, -9.026, 1500, {true, 70});

            intake.move(-127);

            pros::delay(1250);
            leftWingPiston.set_value(false);
            rightWingPiston.set_value(false);
            break;
        case 6: // provs 6ball
            chassis.moveToPoint(0, 0, 1000);

            intake.move_voltage(-10000);
            pros::delay(200);
            intake.move_voltage(0);

            intake.move_voltage(12000);
            pros::delay(10);
            chassis.moveToPoint(0.413, 7.646, 1000);
            chassis.moveToPoint(1.033, -28.105, 1000, {false});
            chassis.moveToPoint(16.945, -43.603, 1150, {false, 40});
            tailPiston.set_value(false);
            pros::delay(10);
            chassis.moveToPoint(28.891, -35.537, 1250, {false});
            tailPiston.set_value(true);
            pros::delay(10);
            chassis.moveToPoint(34.539, -57.983, 1000, {false}, 127);    
            chassis.moveToPoint(9.093, -46.083, 1000);
            chassis.moveToPoint(36.511, -46.91, 1000);
            pros::delay(100);
            intake.move_voltage(-12000);
            chassis.moveToPoint(.292, -45.67, 1050, {false});
            intake.move_voltage(0);
            pros::delay(10);
            chassis.moveToPoint(31.717, -4.093, 1250, {true});
            intake.move_voltage(12000);
            pros::delay(500);
            chassis.moveToPoint(55.309, -15.373, 1000, {true});
            chassis.turnToPoint(55.309, -1000, 500);
            intake.move_voltage(-12000);
            pros::delay(10);
            chassis.moveToPoint(55.342, -30.138, 1050, {true});
            intake.move_voltage(12000);
            pros::delay(10);
            chassis.moveToPoint(55.929,-1.399, 1250);
            chassis.moveToPoint(55.929, -10.399, 1000, {false});
            leftWingPiston.set_value(true);
            pros::delay(10);
            chassis.moveToPoint(55.135, -40.931, 1200);
            chassis.moveToPoint(46.496, -10.952, 1250, {false});
            leftWingPiston.set_value(false);
            pros::delay(10);
            break;
        case 7: // beta better skills push triball at beginning
            chassis.moveToPoint(0, 0, 1500);
            chassis.moveToPoint(-14.466, -31.411, 1500, {false});
            chassis.moveToPoint(-11.96, -16.292, 1500);

            chassis.turnToHeading(110, 1500);
            tailPiston.set_value(false);

            slapper.move_voltage(12000);
            pros::delay(41250);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10: // PID tuner
            chassis.turnToHeading(90, 1000);
            chassis.turnToHeading(270, 1000);
            chassis.moveToPoint(0, 24, 10000);
            //strait::moveRaw(12000, 2000);

            // chassis.turnToHeading(90, 1000);
            break;
    }
}
