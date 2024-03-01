#include "deviceGlobals.hpp"
#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::delay(10);
    pros::Task telemetryTask([&]() {
        strait::selector::init();
        chassis.calibrate();

        // while (true) {
        //     // printf("X: %f, Y: %f, Theta: %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        //     // pros::delay(1000);

        //     if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
        //         printf("chassis.moveToPoint(%f, %f, 1500, true, 127);\n", chassis.getPose().x, chassis.getPose().y);
        //         //printf("chassis.moveToPose(%f, %f, %f, 1500);\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        //     }
        //     if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        //         printf("chassis.moveToPoint(%f, %f, 1500, false, 127);\n", chassis.getPose().x, chassis.getPose().y);
        //         //printf("chassis.moveToPose(%f, %f, %f, 1500);\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        //     }

        //     pros::delay(10);
        // }
    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 

void disabled() {
    bodyLED.clear();
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    //chassis.calibrate();
    // Initialize the auton selector on brain LCD
    //selectorInit();
}