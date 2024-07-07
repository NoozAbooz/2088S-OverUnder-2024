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

using namespace strait;
void autonomous() {
    chassis.setPose(0,0,0);

    switch(selector::auton) {
        case 1: // Do nothing
        chassis.moveToPoint(0, 0, 5000);
        chassis.moveToPoint(0, 1, 1500);
        intake.move_voltage(12000);
        chassis.moveToPoint(0.544, -31.544, 1500, {false});
        chassis.moveToPoint(29.64, -49.219, 1500, {false});
        chassis.moveToPoint(10.333, -45.956, 1500, {false});
        chassis.moveToPoint(10.333, -25.956, 1500, {true});
        chassis.moveToPoint(10.333, -45.956, 1500, {true});
        intake.move_voltage(12000);
        chassis.moveToPoint(34.263, 7.342, 1500);
        chassis.moveToPoint(41.333, -20.026, 1500);
        pros::delay(2500);
        intake.move_voltage(-12000);
        pros::delay(2500);
        intake.move_voltage(12000);
        chassis.moveToPoint(58.465, 2.342, 1500);
        chassis.moveToPoint(57.921, -31.535, 1500);

            break;
        case 3: // close side awp disrupt
            chassis.moveToPoint(0, 0, 1);
            intake.move_voltage(12000);
            pros::delay(100);
            leftWingPiston.set_value(true); // wing open nudge triball to goal
            pros::delay(100);
            leftWingPiston.set_value(false);
            chassis.moveToPoint(7.66, 42.342, 1500); // centre triball rush
            pros::delay(200);
            chassis.moveToPoint(-18, 8, 1500, {false}); // come back

            chassis.turnToHeading(150, 1000);

            intake.move_voltage(-12000);
            pros::delay(1000);
            chassis.turnToHeading(180, 800);
            chassis.moveToPoint(-28, 23, 1000, {false, 80, 127}); // jam it in 😏
            chassis.moveToPoint(-28, 23, 1000, {true, 80, 127});
            chassis.moveToPoint(-28, 23, 800, {false, 80, 127});
            
            chassis.setPose(0, 0, 0); //reset
            chassis.moveToPoint(0, 0, 1500);
            chassis.moveToPoint(-3.091, 12.126, 1500);
            chassis.moveToPoint(-13.553, 25.203, 1500);
            
            break;
        case 4: //descore only
            tailPiston.set_value(true);
            pros::delay(600);
            chassis.turnToHeading(315, 1000);
            pros::delay(1000);
            tailPiston.set_value(false);
            pros::delay(1000);
            leftWingPiston.set_value(true);
            intake.move_voltage(-12000);
           chassis.moveToPoint(1.149, 32.079, 5000, {true, 40});
            break;
        case 6: //6 ball
            chassis.moveToPoint(0, 0, 1500);
            intake.move_voltage(12000);
            rightWingPiston.set_value(true);
            pros::delay(150);
            rightWingPiston.set_value(false);
            chassis.moveToPoint(-10.021, 52.659, 1300);
            chassis.moveToPoint(0.278, -4.34, 1300, {false});
            chassis.turnToHeading(90, 600);
            pros::delay(80);
            intake.move_voltage(-12000);
            pros::delay(500);
            chassis.turnToHeading(270, 500);
            intake.move_voltage(12000);
            chassis.moveToPoint(-34.67, -3.619, 1100);
            chassis.moveToPoint(-1.68, -5.289, 800, {false});
            chassis.moveToPoint(15.773, 11.134, 800, {false});
            tailPiston.set_value(true);
            pros::delay(500);
            tailPiston.set_value(false);
            chassis.moveToPoint(15.773, 20.227, 600, {false});
            intake.move_voltage(0);
            chassis.moveToPoint(16.946, 16.794, 800);
            rightWingPiston.set_value(true);
            chassis.turnToHeading(0, 800);
            intake.move_voltage(-12000);
            chassis.moveToPoint(16.546, 25.505, 1300);
            chassis.moveToPoint(16.701, 12.299, 800, {false});
            rightWingPiston.set_value(false);
            chassis.turnToHeading(310, 400);
            intake.move_voltage(12000);
            chassis.moveToPoint(-32.505, 32.618, 1100);
            chassis.moveToPoint(-12.526, 52, 1100);
            chassis.turnToHeading(90, 400);
            intake.move_voltage(-12000);
            pros::delay(500);
            intake.move_voltage(12000);
            chassis.turnToHeading(270, 400);
            chassis.moveToPoint(-33.783, 53.443, 1500);
            rightWingPiston.set_value(true);
            leftWingPiston.set_value(true);
            chassis.turnToHeading(90, 500);
            chassis.moveToPoint(11.412, 53.443, 1000);
            break;
        case 5: //push one triball for safety 
            chassis.moveToPoint(0, 0, 1000);
            chassis.moveToPoint(0, 40, 2000, {.minSpeed = 127});
            chassis.moveToPoint(0, -20, 2000, {.forwards = false});
            chassis.moveToPoint(0, 30, 2000);
        case 9: // PID tuner
            chassis.moveToPoint(0, 24, 2000);
            chassis.turnToHeading(90, 1000);
            //chassis.turnToHeading(270, 1000);
            //chassis.moveToPoint(0, 24, 10000);
            //strait::moveRaw(12000, 2000);

            // chassis.turnToHeading(90, 1000);
            break;

    }
}
