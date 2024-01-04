#include "main.h"

void far_1tri() {
    chassis.arcade(-127, 0);

    pros::delay(4000);

    chassis.arcade(42, 0);

    pros::delay(1000);

    chassis.arcade(0, 0);

    liftPiston.extend();
}