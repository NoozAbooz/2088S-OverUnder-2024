/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Defines all motors and sensors. Also sets up the chasis and additional sensor info for autonomous.
 */

#include "main.h"

/* Declare functional components */

//-- Booleans //--
bool cataLoaded = false;

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::Motor frontLeft(20, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor backLeft(19, pros::E_MOTOR_GEAR_BLUE, true);
pros::Motor frontRight(18, pros::E_MOTOR_GEAR_BLUE, false);
pros::Motor backRight(17, pros::E_MOTOR_GEAR_BLUE, false);

pros::MotorGroup leftSide({frontLeft, backLeft});
pros::MotorGroup rightSide({frontRight, backRight});

// Intake
pros::Motor intake(10, pros::E_MOTOR_GEAR_GREEN, true);

// Catapult
pros::Motor catapultLeft(6, pros::E_MOTOR_GEAR_RED, false);
pros::Motor catapultRight(7, pros::E_MOTOR_GEAR_RED, true);
pros::MotorGroup catapult({catapultLeft, catapultRight});

// Expansion
pros::Motor expansion(1, pros::E_MOTOR_GEAR_RED, false);

// LED
pros::ADILed bodyLED('E', 64);

/* Declare sensors */
// Inertial
pros::Imu inertialSensor(2);

// Cata Position
pros::ADIAnalogIn cataPosition('A');

// Horizontal tracking wheel encoder
pros::ADIEncoder trackingWheel('B', 'C', true);

/* Auton setup with lemlib */
// Setup drivetrain
lemlib::Drivetrain_t drivetrain {
    &leftSide,
    &rightSide,
    15, // Chassis width
    3.25, // Wheel diameter
    360 // Wheel rpm (after gear ratio)
};

// Tracking wheel info
lemlib::TrackingWheel horizontal_tracking_wheel(&trackingWheel, 2.75, 1);
lemlib::OdomSensors_t sensors {
    nullptr,
    nullptr,
    &horizontal_tracking_wheel,
    nullptr,
    &inertialSensor
};

/* PID Calibration */
// Front/back PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};

// Turning/angle PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};

// Create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);