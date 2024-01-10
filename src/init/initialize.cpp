/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Extra code that runs on robot init (mainly auton selector)
 */

#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    //pros::lcd::initialize();
    //chassis.calibrate();

    selector::init();

    pros::Task screenTask([&]() {
        chassis.calibrate();

        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            //pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            //pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            //pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            //lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            printf("X: %f, Y: %f, Theta: %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
            // delay to save resources
            pros::delay(50);
        }
    });


    //selectorInit();

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
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
    // Initialize the auton selector on brain LCD
    //selectorInit();
}