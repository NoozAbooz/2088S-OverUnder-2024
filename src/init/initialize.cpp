#include "main.h"
#include "globals.hpp"

#include "gif-pros/gifclass.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    //-- Render funny gif on screen //--
    lv_obj_t* obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 540, 300);
    lv_obj_align(obj, LV_ALIGN_CENTER, 30, 30);
    static Gif gif("/usd/logo.gif", lv_scr_act());

	cycleGradient(leftLED, "#215071", "#74aacc", 15);

    //pros::delay(500);

    loadCatapult();
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

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    //leftLED.clear();
}