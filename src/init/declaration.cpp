#include "main.h"

/* Physical Devices */
// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Intake
pros::Motor intake(-3, pros::v5::MotorGears::blue);

// Catapult
pros::Motor catapult(1, pros::v5::MotorGears::red);

// Pneumatics
pros::adi::Pneumatics wingPiston('G', false);

// LED


/* Sensors */

// Cata Position
pros::adi::AnalogIn cataLineSensor('A');

// Inertial
pros::Imu inertial(6);