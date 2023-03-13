/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Defines all motors and sensors. Also sets up the chasis and additional sensor info for autonomous.
 * @date 2023-03-10
 */

#include "main.h"

/* Declare main ports */
// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::Motor frontLeft(1, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor midLeft(2, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor backLeft(3, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor frontRight(4, pros::E_MOTOR_GEAR_GREEN, true);
pros::Motor midRight(5, pros::E_MOTOR_GEAR_GREEN, true);
pros::Motor backRight(6, pros::E_MOTOR_GEAR_GREEN, true);

pros::MotorGroup leftSide({frontLeft, midLeft, backLeft});
pros::MotorGroup rightSide({frontRight, midRight, backRight});

// Intake
pros::Motor intake(14, pros::E_MOTOR_GEAR_BLUE, false);

// Catapult
pros::Motor catapult(9, pros::E_MOTOR_GEAR_RED, true);

// LED Lights
auto bodyLED = sylib::Addrled(22, "B", 64); // Smart expander port, ADI port,number, # of pixels

/* Declare sensors */
// Inertial
pros::Imu inertial(17);

// Cata Rotation
pros::ADIPotentiometer cataRot(CATA_POTENTIOMETER_PORT);

// Horizontal tracking wheel encoder
pros::ADIEncoder horizontalTrackingWheel('C', 'D', false);

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
lemlib::TrackingWheel horizontal_tracking_wheel(&HorizontalTrackingWheel, 2.75, -4.6);
lemlib::OdomSensors_t sensors {
    &horizontal_tracing_wheel,
    nullptr,
    nullptr,
    nullptr,
    &inertial
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
lemlib::Chassis chassis(drivetrain, sensors, lateralController, angularController);