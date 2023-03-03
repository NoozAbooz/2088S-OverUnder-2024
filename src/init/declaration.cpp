#include "main.h"
#include "pros/motors.h"
#include "pros/optical.h"

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::Motor frontLeft(2, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor frontRight(13, pros::E_MOTOR_GEAR_GREEN, true);
pros::Motor backLeft(3, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor backRight(14, pros::E_MOTOR_GEAR_GREEN, true);

// Intake
pros::Motor intake(15, pros::E_MOTOR_GEAR_BLUE, false);

// Catapult
pros::Motor catapult(20, pros::E_MOTOR_GEAR_RED, false);

// Roller
pros::Motor roller(5, pros::E_MOTOR_GEAR_GREEN, true);

// Expansion
pros::Motor expansion(19, pros::E_MOTOR_GEAR_RED, false);

// Catapult Sensor
#define CATA_SENSOR_PORT 'H'
pros::ADIDigitalIn cataStatus(CATA_SENSOR_PORT);
