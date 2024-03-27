#include "lemlib/chassis/trackingWheel.hpp"
#include "main.h"
#include "pros/motors.hpp"

/* Declare functional components */

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::MotorGroup leftDrive({-11, -13, -14});
pros::MotorGroup rightDrive({6, 7, 8});

// Intake
pros::Motor intake(-10);
pros::Motor slapper(3);

// Pneumatics
pros::ADIDigitalOut wingsPiston('C');
pros::ADIDigitalOut liftPiston('D');
pros::ADIDigitalOut tailPiston('E', true);

/* Declare sensors */
pros::ADILed lightStrip('B', 64);
pros::ADIPotentiometer potentiometer('A');

pros::Imu inertial(20);
pros::Imu inertial2(21);
// pros::Rotation verticalEnc(15, true);
// lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, -3.7);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              12.5, // 25 hole track width
                              lemlib::Omniwheel::NEW_325,
                              450, // drivetrain rpm
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);
// lateral motion controller
lemlib::ControllerSettings linearController(21, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            24, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);
// angular motion controller
lemlib::ControllerSettings angularController(5, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             40, // derivative gain (kD)
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