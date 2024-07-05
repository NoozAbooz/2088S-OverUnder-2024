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
            chassis.moveToPoint(-28, 30, 1000, {false, 80, 127}); // jam it in 😏
            chassis.moveToPoint(-28, 34, 1000, {true, 80, 127});
            chassis.moveToPoint(-28, 40, 800, {false, 80, 127});
            
            chassis.setPose(0, 0, 0); //reset
            chassis.moveToPoint(0, 0, 1500);
            chassis.moveToPoint(-3.091, 12.126, 1500);
            chassis.moveToPoint(-13.553, 25.203, 1500);
            
            break;
                
        case 6: //6 ball
            chassis.moveToPoint(0, 0, 1500);
            intake.move_voltage(12000);
            rightWingPiston.set_value(true);
            pros::delay(150);
            rightWingPiston.set_value(false);
            chassis.moveToPoint(-10.021, 50.659, 1300);
            chassis.moveToPoint(0.278, -4.34, 1300, {false});
            chassis.turnToHeading(90, 600);
            pros::delay(100);
            intake.move_voltage(-12000);
            pros::delay(500);
            chassis.turnToHeading(270, 500);
            intake.move_voltage(12000);
            chassis.moveToPoint(-31.67, -3.619, 1100);
            chassis.moveToPoint(-1.68, -5.289, 800, {false});
            chassis.moveToPoint(15.773, 11.134, 800, {false});
            tailPiston.set_value(true);
            pros::delay(500);
            tailPiston.set_value(false);
            chassis.moveToPoint(15.773, 29.227, 600, {false});
            intake.move_voltage(0);
            chassis.moveToPoint(16.946, 16.794, 800);
            rightWingPiston.set_value(true);
            chassis.turnToHeading(0, 400);
            pros::delay(200);
            intake.move_voltage(-12000);
            chassis.moveToPoint(21.546, 34.505, 1000);
            chassis.moveToPoint(16.701, 12.299, 800, {false});
            rightWingPiston.set_value(false);
            chassis.turnToHeading(310, 400);
            intake.move_voltage(12000);
            chassis.moveToPoint(-32.505, 30.618, 900);
            chassis.moveToPoint(-12.526, 52, 900);
            chassis.turnToHeading(90, 400);
            intake.move_voltage(-12000);
            pros::delay(500);
            intake.move_voltage(12000);
            chassis.turnToHeading(270, 400);
            chassis.moveToPoint(-29.783, 55.443, 1300);
            rightWingPiston.set_value(true);
            leftWingPiston.set_value(true);
            chassis.turnToHeading(90, 500);
            chassis.moveToPoint(11.412, 55.443, 1000);
            break;
        case 4: // beta skills // beta better skills push triball at beginning
            chassis.moveToPoint(0, 0, 1500);
            chassis.moveToPoint(-14.466, -31.411, 1500, {false});
            chassis.moveToPoint(-11.96, -16.292, 1500);
            intake.move_voltage(-12000);
            chassis.turnToHeading(110, 1500);
            tailPiston.set_value(true);

            pros::delay(50000);
            tailPiston.set_value(false);

            break;
        case 5: //push one triball for safety 
            chassis.moveToPoint(0, 0, 1000);
            chassis.moveToPoint(0, -40, 2000, {.forwards = false, .minSpeed = 127});
            chassis.moveToPoint(0, -20, 2000);
            chassis.moveToPoint(0, -30, 2000, {.forwards = false, .minSpeed = 127});
            chassis.moveToPoint(0, -20, 2000);
            chassis.moveToPoint(0, -30, 2000, {.forwards = false, .minSpeed = 127});
        case 9: // PID tuner
            chassis.turnToHeading(90, 1000);
            chassis.turnToHeading(270, 1000);
            //chassis.moveToPoint(0, 24, 10000);
            //strait::moveRaw(12000, 2000);

            // chassis.turnToHeading(90, 1000);
            break;

    }
}
