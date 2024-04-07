#include "abstractGlobals.hpp"
#include "deviceGlobals.hpp"
#include "libSTRAITIS/drivetrain/chassis.hpp"
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
            chassis.moveToPoint(0, 0, 5000);
            chassis.moveToPoint(-7.66, 46.342, 5000);
            chassis.moveToPoint(6.511, -7.277, 5000);
            chassis.moveToPoint(-25.469, -8.043, 5000);
            chassis.moveToPoint(9.192, -6.128, 5000);
            chassis.moveToPoint(26.618, 8.617, 5000);
            chassis.moveToPoint(26.043, 24.894, 5000);
            chassis.moveToPoint(25.277, 7.851, 5000);
            chassis.moveToPoint(25.66, 24.703, 5000);
            chassis.moveToPoint(19.341, 7.468, 5000);
            chassis.moveToPoint(-25.086, 26.235, 5000);
            chassis.moveToPoint(13.213, 39.065, 5000);
            chassis.moveToPoint(-26.426, 50.363, 5000);
            chassis.moveToPoint(12.639, 50.938, 5000);
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
            chassis.moveToPoint(0, 0, 5000);
            chassis.moveToPoint(-7.66, 46.342, 5000);
            chassis.moveToPoint(6.511, -7.277, 5000);
            chassis.moveToPoint(-25.469, -8.043, 5000);
            chassis.moveToPoint(9.192, -6.128, 5000);
            chassis.moveToPoint(26.618, 8.617, 5000);
            chassis.moveToPoint(26.043, 24.894, 5000);
            chassis.moveToPoint(25.277, 7.851, 5000);
            chassis.moveToPoint(25.66, 24.703, 5000);
            chassis.moveToPoint(19.341, 7.468, 5000);
            chassis.moveToPoint(-25.086, 26.235, 5000);
            chassis.moveToPoint(13.213, 39.065, 5000);
            chassis.moveToPoint(-26.426, 50.363, 5000);
            chassis.moveToPoint(12.639, 50.938, 5000);
            break;
        case 5: 
            break;
        case 6: 
            break;
        case 7: // beta better skills push triball at beginning
            chassis.moveToPoint(0, 0, 1500);
            chassis.moveToPoint(-14.466, -31.411, 1500, {false});
            chassis.moveToPoint(-11.96, -16.292, 1500);

            chassis.turnToHeading(110, 1500);
            tailPiston.set_value(false);

            slapper.move_voltage(12000);
            pros::delay(45000);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10: // PID tuner
            chassis.moveToPoint(0, 0, 1000);
            chassis.moveToPoint(0, 96, 10000);
            //strait::moveRaw(12000, 2000);

            // chassis.turnToHeading(90, 1000);
            break;
    }
}
