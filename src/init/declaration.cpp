#include "globals.hpp"

/* Physical Devices */
// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::MotorGroup leftDrive({-8, -17, -10});
pros::MotorGroup rightDrive({18, 19, 20});

// Intake
pros::Motor intake(-7, pros::v5::MotorGears::blue);

// Catapult
pros::Motor catapult(1, pros::v5::MotorGears::red);

// Pneumatics
pros::adi::Pneumatics intakePiston('H', false);   
pros::adi::Pneumatics wingPiston('b', false);

// LED
pros::adi::Led leftLED('D', 64);
pros::adi::Led rightLED('F', 64);

/* Sensors */
// Inertial
pros::Imu imu(2);

// Cata Position
pros::adi::AnalogIn cataLineSensor('A');


// Horizontal tracking wheel encoder
pros::adi::Encoder horizontalEnc('B', 'C', true);