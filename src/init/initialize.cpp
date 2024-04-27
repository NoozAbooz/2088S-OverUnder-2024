#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::delay(10);

    static Gif gif("/usd/logo2.gif", lv_scr_act());
    strait::selector::init();
    
    pros::Task bruh(strait::calibrateIMU);
    chassis.calibrate();
    pros::Task odomTask(strait::odomThread);

    // pros::Task telemetryTask([&]() {
        // int timer = 0;
        // std::deque<double> buffer;
        // int windowSize = 20; // Adjust this value as needed
        // FILE *save_file;
        // save_file = fopen("/usd/log.txt", "w");

        // while (true) {
        //     printf("Theta: %f\n", inertial.get_heading());
        //     pros::delay(100);
        // //     printf("X: %f, Y: %f, Theta: %f\n", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

        // //     pros::c::imu_accel_s_t accel = inertial.get_accel();
        // //     double filteredAccelY = strait::median_filter(buffer, accel.y, windowSize);
        // //     printf("%d,%f,%f\n", timer, accel.y, chassis.getPose().y);
        // //     fprintf(save_file, "%d,%f,%f\n", timer, filteredAccelY, chassis.getPose().y);

        // //     timer += 1;
        // //     pros::delay(1);

        // //     if (timer > 10000) {
        // //         fclose(save_file);
        // //         break;
        // //     }
        // }
    // });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
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
}