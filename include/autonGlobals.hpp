#pragma once
#include "main.h"

// Auton
void far_1tri();
void skills();

/* LemLib */

// Drivetrain
auto inline leftDrive = lemlib::makeMotorGroup({-16, -17, -18}, pros::v5::MotorGears::blue);
auto inline rightDrive = lemlib::makeMotorGroup({1, 2, 3}, pros::v5::MotorGears::blue);

// horizontal tracking wheel. Port 4, 2.75" diameter, 3.7" offset, back of the robot
//lemlib::TrackingWheel horizontal(4, lemlib::Omniwheel::NEW_275, -3.7);

// drivetrain settings
inline lemlib::Drivetrain drivetrain(
	leftDrive, // left motor group
    rightDrive, // right motor group
    13.5, // 10 inch track width
    lemlib::Omniwheel::OLD_275, // using new 3.25" omnis
    450, // drivetrain rpm is 360
    2 // chase power is 2. If we had traction wheels, it would have been 8
);

// linear motion controller
inline lemlib::ControllerSettings linearController(
	10, // proportional gain (kP)
    30, // derivative gain (kD)
    1, // small error range, in inches
    100, // small error range timeout, in milliseconds
    3, // large error range, in inches
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

// angular motion controller
inline lemlib::ControllerSettings angularController(
	2, // proportional gain (kP)
    10, // derivative gain (kD)
    1, // small error range, in degrees
    100, // small error range timeout, in milliseconds
    3, // large error range, in degrees
    500, // large error range timeout, in milliseconds
    20 // maximum acceleration (slew)
);

// sensors for odometry
// note that in this example we use internal motor encoders, so we don't pass vertical tracking wheels
inline lemlib::OdomSensors sensors(
	nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
    nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
    nullptr, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &inertial // inertial sensor
);

// create the chassis
inline lemlib::Differential chassis(drivetrain, linearController, angularController, sensors);