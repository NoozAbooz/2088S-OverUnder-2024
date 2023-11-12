#include "main.h"

/* Physical Devices */
// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::MotorGroup leftSide({-11, -12, -13}, pros::v5::MotorGears::blue);
pros::MotorGroup rightSide({16, 17, 18}, pros::v5::MotorGears::blue);

// Intake
pros::Motor intake(-1, pros::v5::MotorGears::blue);

// Catapult
pros::Motor catapult(-20, pros::v5::MotorGears::red);

// Pneumatics
pros::adi::Pneumatics intakePiston('a', false);   
pros::adi::Pneumatics wingPiston('b', false);

// LED
pros::adi::Led leftLED('E', 64);
pros::adi::Led rightLED('E', 64);

/* Sensors */
// Inertial
pros::Imu imu(2);

// Cata Position
pros::adi::AnalogIn cataLineSenor('A');
pros::adi::DigitalIn cataLimitSwitch('B');


// Horizontal tracking wheel encoder
pros::adi::Encoder horizontalEnc('B', 'C', true);
// lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -3.7);

/* Lemlib */
// lemlib::Drivetrain_t drivetrain {
//     &leftSide, // left drivetrain motors
//     &rightSide, // right drivetrain motors
//     15, // track width
//     lemlib::Omniwheel::NEW_4, // using new 4" omnis
//     257.14, // wheel rpm
//     8 // chase power is 2. If we had traction wheels, it would have been 8
// };

// lemlib::OdomSensors_t sensors {
//     nullptr, // vertical tracking wheel 1
//     nullptr, // vertical tracking wheel 2
//     &horizontal, // horizontal tracking wheel 1
//     nullptr, // we don't have a second tracking wheel, so we set it to nullptr
//     &imu // inertial sensor
// };

// // forward/backward PID
// lemlib::ChassisController_t lateralController {
//     10, // proportional gain (kP)
//     30, // derivative gain (kD)
//     1, // small error range, in inches
//     100, // small error range timeout, in milliseconds
//     3, // large error range, in inches
//     500, // large error range timeout, in milliseconds
//     20 // maximum acceleration (slew)
// };
 
// // turning PID
// lemlib::ChassisController_t angularController {
//     2, // proportional gain (kP)
//     10, // derivative gain (kD)
//     1, // small error range, in degrees
//     100, // small error range timeout, in milliseconds
//     3, // large error range, in degrees
//     500, // large error range timeout, in milliseconds
//     20 // maximum acceleration (slew)
// };

// // create the chassis
// lemlib::Differential chassis(drivetrain, lateralController, angularController, sensors);