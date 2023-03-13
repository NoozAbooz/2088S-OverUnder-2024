/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Defines all motors and sensors. Also sets up the chasis and additional sensor info for autonomous.
 * @date 2023-03-10
 */

#include "main.h"

/* Declare main parts */
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
auto bodyLED = sylib::Addrled(1, 3, 64); 

/* Declare sensors */
// Inertial
pros::Imu inertial(17);

// Cata Rotation
#define CATA_POTENTIOMETER_PORT 'A'
pros::ADIAnalogIn cataRot(CATA_POTENTIOMETER_PORT);

// left tracking wheel encoder
pros::ADIEncoder left_enc('A', 'B', true); // ports A and B, reversed
// right tracking wheel encoder
pros::Rotation right_rot(1, false); // port 1, not reversed
// back tracking wheel encoder
pros::ADIEncoder back_enc('C', 'D', false); // ports C and D, not reversed

/* Auton setup with lemlib */

// Setup drivetrain
lemlib::Drivetrain_t drivetrain {
    &leftSide, // left drivetrain motors
    &rightSide, // right drivetrain motors
    10, // track width
    3.25, // wheel diameter
    360 // wheel rpm
};

// Tracking wheel info
lemlib::TrackingWheel left_tracking_wheel(&left_enc, 2.75, -4.6); // 2.75" wheel diameter, -4.6" offset from tracking center
lemlib::TrackingWheel right_tracking_wheel(&right_rot, 2.75, 1.7); // 2.75" wheel diameter, 1.7" offset from tracking center
lemlib::TrackingWheel back_tracking_wheel(&back_enc, 2.75, 4.5); // 2.75" wheel diameter, 4.5" offset from tracking center

lemlib::OdomSensors_t sensors {
    &left_tracking_wheel, // vertical tracking wheel 1
    &right_tracking_wheel, // vertical tracking wheel 2
    &back_tracking_wheel, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial // inertial sensor
};

/* PID Calibration */

// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};

// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);