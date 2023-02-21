#include "main.h"

// Intake
pros::Motor intake(6, pros::E_MOTOR_GEAR_GREEN, true);

// Catapult
pros::Motor flywheel(8, pros::E_MOTOR_GEAR_RED, false);

// Roller
pros::Motor roller(19, pros::E_MOTOR_GEAR_GREEN, true);

// Expansion
pros::Motor expansion(20, pros::E_MOTOR_GEAR_RED, false);

// Roller Colour Sensor
pros::Optical rollerColour(13);