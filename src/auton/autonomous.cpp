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
        case 2: // NORUSH 6-ball far side start with preload under alley early season
            chassis.moveToPoint(0, 0, 1500);
            intake.move_voltage(12000);
            chassis.moveToPoint(-0.382, 3.645, 1000);
            chassis.moveToPoint(4.294, -25.229, 1000, {false});
            chassis.moveToPoint(-1.147, -33.066, 1000, {false, 70});
            chassis.moveToPoint(15.099, -48.739, 1000, {false, 70});
            tailPiston.set_value(false);

            chassis.turnToPoint(100, -60, 1500);
            pros::delay(1000);
            intake.move_velocity(-12000);

            chassis.moveToPoint(28.537, -60, 1500, {true});
            tailPiston.set_value(true);
            intake.move_voltage(0);

            strait::moveRaw(-12000, 1000);
            strait::moveRaw(12000, 1000);
            strait::moveRaw(-12000, 1000);
            break;
        case 3: // new 6ball provs
            chassis.moveToPoint(0, 0, 1000);
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
            wingsPiston.set_value(true);
            pros::delay(10);
            chassis.moveToPoint(55.135, -40.931, 1200);
            chassis.moveToPoint(46.496, -10.952, 1250, {false});
            wingsPiston.set_value(false);
            pros::delay(10);
            break;
        case 4: // Elims disrupt
            chassis.moveToPoint(0, 0, 1500);
            chassis.moveToPoint(0.503, 53.737, 1500); //move to field centre
            pros::delay(1000);
            chassis.turnToPoint(100, 53, 1500); //turnto other offensive zone

            pros::delay(500);
            wingsPiston.set_value(true); //open wings
            chassis.moveToPoint(27.392, 53.734, 1500); //move to barrier for plow

            pros::delay(1000);
            wingsPiston.set_value(false);

            // intake.move_voltage(-12000); //outtake into other offensive zone
            // pros::delay(2000); 
            // intake.move_voltage(0);

            chassis.turnToPoint(-100, 55, 1500); // outtake into opponent goal
            chassis.moveToPoint(20, 54, 1500);

            pros::delay(500);
            intake.move(-127);

            pros::delay(2000);
            intake.brake();

            chassis.turnToPoint(100, 55, 1500);
            chassis.moveToPoint(-20, 54, 1500, {false});
            break;
        case 5: // Push 1 triball with back
            strait::moveRaw(-12000, 2000);
            strait::moveRaw(12000, 1000);
            strait::moveRaw(-12000, 2000);
            strait::moveRaw(12000, 1000);
            break;
        case 6: // goofy ahh skills dont use
            slapper.move_voltage(12000);
            //pros::delay(1000);
            pros::delay(41500); // run kicker
            slapper.move_voltage(0);

            chassis.moveToPoint(0, 0, 1500);
            chassis.moveToPoint(24.969, 24.772, 2000);
            chassis.moveToPoint(25.952, 54.853, 2000);
            chassis.moveToPoint(109.705, 56.622, 3000); //move to goal

            strait::moveRaw(-12000, 1000); // push repeatedly
            wingsPiston.set_value(true);
            strait::moveRaw(12000, 1500);
            strait::moveRaw(-12000, 1000);
            strait::moveRaw(12000, 3000);
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
        case 9: // AWP close side descore and touch bar
            chassis.moveToPoint(0, 0, 1500);

            // wingsPiston.set_value(true);
            // pros::delay(600);
            // wingsPiston.set_value(false); //open wings for triball

            tailPiston.set_value(false);
            pros::delay(600);
            chassis.turnToHeading(-90, 1000);
            pros::delay(600);
            tailPiston.set_value(true); //descore turn -90deg
            chassis.turnToPoint(10, -100, 1000, {true, 100});
            chassis.turnToPoint(100, -20, 1000, {true, 100});

            //chassis.moveToPoint(0, 25.339, 1000, false);

            // chassis.moveToPoint(8, 28.738, 1500, false, 80);
            // chassis.moveToPoint(51.521, 10.238, 1500, false, 80);
            // pros::delay(2000);
            // tailPiston.set_value(false);
            // strait::moveRaw(-12000, 10000);

            chassis.moveToPoint(8.811, -8.277, 1500);
            chassis.moveToPoint(36, -8.026, 1500, {true, 60});

            intake.move(-127);
            break;
        case 10: // PID tuner
            chassis.moveToPoint(0, 0, 1000);
            chassis.moveToPoint(0, 96, 10000);
            //strait::moveRaw(12000, 2000);

            // chassis.turnToHeading(90, 1000);
            break;
    }
}
