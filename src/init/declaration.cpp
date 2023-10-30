#include "main.h"

/* Physical Devices */
// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
pros::MotorGroup leftSide({-20, -19, -18}, pros::v5::MotorGears::blue);
pros::MotorGroup rightSide({17, 16, 15}, pros::v5::MotorGears::blue);

// Intake
pros::Motor intake(-10, pros::v5::MotorGears::blue);

// Catapult
pros::Motor catapult(6, pros::v5::MotorGears::red);

// Pneumatics


// LED
pros::adi::Led bodyLED('E', 64);

/* Sensors */
// Inertial
pros::Imu inertialSensor(2);

// Cata Position
pros::adi::AnalogIn cataPosition('A');

// Horizontal tracking wheel encoder
pros::adi::Encoder trackingWheel('B', 'C', true);