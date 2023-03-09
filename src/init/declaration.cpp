#include "main.h"

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::Motor frontLeft(2, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor backLeft(3, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor frontRight(13, pros::E_MOTOR_GEAR_GREEN, true);
pros::Motor backRight(14, pros::E_MOTOR_GEAR_GREEN, true);

pros::MotorGroup leftSide({frontLeft, backLeft});
pros::MotorGroup rightSide({frontRight, backRight});

// Intake
pros::Motor intake(15, pros::E_MOTOR_GEAR_BLUE, false);

// Catapult
pros::Motor catapult(20, pros::E_MOTOR_GEAR_RED, true);

// Roller
pros::Motor roller(5, pros::E_MOTOR_GEAR_GREEN, true);

// Expansion
pros::Motor expansion(19, pros::E_MOTOR_GEAR_RED, false);

lemlib::Drivetrain_t drivetrain {
    &leftSide, // left drivetrain motors
    &rightSide, // right drivetrain motors
    10, // track width
    3.25, // wheel diameter
    360 // wheel rpm
};