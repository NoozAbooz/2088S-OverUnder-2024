/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Defines all motors and sensors. Also sets up the chasis and additional sensor info for autonomous.
 */

#include "declaration.hpp"
#include "main.h"

/* Declare functional components */

//-- Booleans //--
bool cataLoaded = false;

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::MotorGroup leftSide({-8, -17, -10});
pros::MotorGroup rightSide({18, 19, 20});

// Intake
pros::Motor intake(-3);

// LED
pros::ADILed bodyLED('E', 64);

/* Declare sensors */
// Inertial
pros::Imu inertial(6);

// Cata Position
pros::ADIAnalogIn cataPosition('A');

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftSide, // left motor group
                              &rightSide, // right motor group
                              15, // 10 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 3.25" omnis
                              257.14, // drivetrain rpm is 360
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            10 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors for odometry
// note that in this example we use internal motor encoders, so we don't pass vertical tracking wheels
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial // inertial sensor
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);