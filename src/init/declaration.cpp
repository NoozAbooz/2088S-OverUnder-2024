#include "main.h"

/* Declare functional components */

//-- Booleans //--
bool cataLoaded = false;

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::MotorGroup leftDrive({-8, -9, -10});
pros::MotorGroup rightDrive({18, 19, 20});

pros::Motor driveMotor(8);

// Intake
pros::Motor intake(-15);

pros::Motor slapper(6);

// LED
pros::ADILed bodyLED('A', 64);

// Pneumatics
pros::ADIDigitalOut wingsPiston('H');
pros::ADIDigitalOut liftPiston('G');

/* Declare sensors */
// Inertial
pros::Imu inertial(5);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              13.5, // 10 inch track width
                              lemlib::Omniwheel::OLD_275, // using new 3.25" omnis
                              450, // drivetrain rpm is 360
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