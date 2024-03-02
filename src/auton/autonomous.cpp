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



/** THE GREAT AUTON INDEX  **/
// 0: Do nothing
// 6: Skills (run kicker only and simple movements to goal)
// 3 new code
// 5: Push 1 triball with back
// 2: NORUSH 6-ball far side start with preload under alley
// 7: RUSH 6-ball

// 9: AWP close side descore and touch bar

// 4: Elims disrupt

using namespace strait;
void autonomous() {
    chassis.setPose(0,0,0);

    if(selector::auton == 2){ //run auton for Far Side 6 Triball NORUSH
        chassis.moveToPoint(0, 0, 1500);
        intake.move_voltage(12000);
        chassis.moveToPoint(-0.382, 3.645, 1000);
        chassis.moveToPoint(4.294, -25.229, 1000, false);
        chassis.moveToPoint(-1.147, -33.066, 1000, false, 70);
        chassis.moveToPoint(15.099, -48.739, 1000, false, 70);
        tailPiston.set_value(false);
        
        chassis.turnTo(100, -60, 1500);
        pros::delay(1000);
        intake.move_velocity(-12000);

        chassis.moveToPoint(28.537, -60, 1500, true);
        tailPiston.set_value(true);
        intake.move_voltage(0);

        moveRaw(-12000, 1000);
        moveRaw(12000, 1000);
        moveRaw(-12000, 1000);
        
    }

    if(selector::auton == 3){ //not rush six ball new
        chassis.moveToPoint(0, 0, 1250);
        chassis.moveToPoint(0.413, 7.646, 1250);
        intake.move_voltage(12000);
        pros::delay(10);
        chassis.moveToPoint(1.033, -28.105, 1250, false);
        chassis.moveToPoint(16.945, -43.603, 1250, false, 40);
        tailPiston.set_value(false);
        pros::delay(10);
        chassis.moveToPoint(28.891, -35.537, 1250, false);
        tailPiston.set_value(true);
        pros::delay(10);
        chassis.moveToPoint(10.539, -42.983, 1250, false, 127);
        chassis.setPose(10.5, -42.983, 270);
        
        chassis.moveToPoint(.924, -42.983, 1250);
        chassis.turnTo(100, 100, 500);
        intake.move_voltage(0);
        pros::delay(10);
        chassis.moveToPoint(.292, -45.67, 1250);
        intake.move_voltage(12000);
        pros::delay(10);
        chassis.moveToPoint(34.717, 9.093, 1250, true, 90);
        chassis.moveToPoint(59.309, -5.373, 1250, true, 90);
        chassis.turnTo(59.309, -1000, 500);
        intake.move_voltage(0);
        pros::delay(10);
        chassis.moveToPoint(60.342, -29.138, 1250, true, 90);
        chassis.setPose(60.342, -29.138, 180);
        intake.move_voltage(12000);
        pros::delay(10);
        chassis.moveToPoint(59.929, 12.399, 1250);
        chassis.moveToPoint(59.929, 12.399, 250, false);
        chassis.turnTo(59.309, -1000, 500);
        wingsPiston.set_value(true);
        pros::delay(10);
        chassis.moveToPoint(60.135, -28.931, 1250);
        chassis.moveToPoint(46.496, -10.952, 1250);
        wingsPiston.set_value(false);
        pros::delay(10);


    }

    if (selector::auton == 4) { //disrupt elims
        chassis.moveToPoint(0, 0, 1500);
        chassis.moveToPoint(0.503, 53.737, 1500); //move to field centre
        pros::delay(1000);
        chassis.turnTo(100, 53, 1500); //turnto other offensive zone

        pros::delay(500);
        wingsPiston.set_value(true); //open wings
        chassis.moveToPoint(27.392, 53.734, 1500); //move to barrier for plow

        pros::delay(1000);
        wingsPiston.set_value(false);

        // intake.move_voltage(-12000); //outtake into other offensive zone
        // pros::delay(2000); 
        // intake.move_voltage(0);

        chassis.turnTo(-100, 55, 1500); // outtake into opponent goal
        chassis.moveToPoint(20, 54, 1500);

        pros::delay(500);
        intake.move(-127);

        pros::delay(2000);
        intake.brake();

        chassis.turnTo(100, 55, 1500);
        chassis.moveToPoint(-20, 54, 1500, false);
    }

    if (selector::auton == 6) { 
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

    if (selector::auton == 5) { //one triball
        strait::moveRaw(-12000, 2000);
    }

    if (selector::auton == 7) { //rush auton w path.jerryio
        chassis.moveToPoint(0, 0, 1500);
chassis.moveToPoint(-14.466, -31.411, 1500,false);
chassis.moveToPoint(-4.96, -15.292, 1500);


chassis.turnTo(100, -50, 1500);


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
        chassis.moveToPoint(0, 0, 1500);

        // wingsPiston.set_value(true);
        // pros::delay(600);
        // wingsPiston.set_value(false); //open wings for triball

        tailPiston.set_value(false);
        pros::delay(600);
        chassis.turnTo(-100, 0, 1000, true, 127);
        pros::delay(600);
        tailPiston.set_value(true); //descore turn -90deg
        chassis.turnTo(10, -100, 1000, true, 100);
        chassis.turnTo(100, -20, 1000, true, 100);

        //chassis.moveToPoint(0, 25.339, 1000, false);

        // chassis.moveToPoint(8, 28.738, 1500, false, 80);
        // chassis.moveToPoint(51.521, 10.238, 1500, false, 80);
        // pros::delay(2000);
        // tailPiston.set_value(false);
        // strait::moveRaw(-12000, 10000);

        chassis.moveToPoint(8.811, -8.277, 1500);
        chassis.moveToPoint(36, -8.026, 1500, true, 60);

        intake.move(-127);
    }

    if (selector::auton == 10) { //PID tuner
        chassis.moveToPoint(0, 0, 1000);
        // chassis.moveToPoint(0, 24, 1000);

        chassis.turnTo(1000000, 0, 10000);
        chassis.turnTo(0, -100, 1500);
        chassis.turnTo(0, 100, 1500);  
    }
}
