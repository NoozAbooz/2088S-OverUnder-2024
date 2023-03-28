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
//pros::Motor frontLeft(1, pros::E_MOTOR_GEAR_BLUE, false);
//pros::Motor backLeft(2, pros::E_MOTOR_GEAR_BLUE, false);
//pros::Motor frontRight(3, pros::E_MOTOR_GEAR_BLUE, true);
//pros::Motor backRight(4, pros::E_MOTOR_GEAR_BLUE, true);

pros::Motor frontLeft(19, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor backLeft(11, pros::E_MOTOR_GEAR_GREEN, false);
pros::Motor frontRight(16, pros::E_MOTOR_GEAR_GREEN, true);
pros::Motor backRight(10, pros::E_MOTOR_GEAR_GREEN, true);

pros::MotorGroup leftSide({frontLeft, backLeft});
pros::MotorGroup rightSide({frontRight, backRight});

// Intake
pros::Motor intake(15, pros::E_MOTOR_GEAR_BLUE, false);

// Catapult
pros::Motor catapult(9, pros::E_MOTOR_GEAR_RED, true);

// LED Lights
auto bodyLED = sylib::Addrled(22, 5, 64); // Smart expander port, ADI port,number, # of pixels

/* Declare sensors */
// Inertial
pros::Imu inertial(14);

// Cata Rotation
pros::ADIPotentiometer cataRot(CATA_POTENTIOMETER_PORT);

// Horizontal tracking wheel encoder
pros::ADIEncoder verticalTrackingWheel('G', 'H', true);
pros::Rotation horizontalTrackingWheel(5, true);

/* Auton setup with lemlib */
// Setup drivetrain
lemlib::Drivetrain_t drivetrain {
    &leftSide,
    &rightSide,
    //15, // Chassis width
    //3.25, // Wheel diameter
    //360 // Wheel rpm (after gear ratio)

    17.5, // Chassis width
    4, // Wheel diameter
    600 // Wheel rpm (after gear ratio)
};

// Tracking wheel info
lemlib::TrackingWheel vertical_tracking_wheel(&verticalTrackingWheel, 2.75, -1);
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontalTrackingWheel, 2.75, 1);
lemlib::OdomSensors_t sensors {
    nullptr,
    nullptr,
    &horizontal_tracking_wheel,
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
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);