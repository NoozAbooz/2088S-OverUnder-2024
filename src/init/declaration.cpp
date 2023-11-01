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
pros::Motor catapult(-6, pros::v5::MotorGears::red);

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

/* Lemlib */
// lemlib::Drivetrain_t drivetrain {
//     &leftSide, // left drivetrain motors
//     &rightSide, // right drivetrain motors
//     15, // track width
//     4, // wheel diameter
//     257 // wheel rpm
// };

// lemlib::TrackingWheel horizontal_tracking_wheel(&trackingWheel, 2.75, -4.6);
// lemlib::OdomSensors_t sensors {
//     &horizontal_tracking_wheel, // vertical tracking wheel 1
//     nullptr, // vertical tracking wheel 2
//     nullptr, // horizontal tracking wheel 1
//     nullptr, // we don't have a second tracking wheel, so we set it to nullptr
//     &inertialSensor // inertial sensor
// };

// // forward/backward PID
// lemlib::ChassisController_t lateralController {
//     8, // kP
//     30, // kD
//     1, // smallErrorRange
//     100, // smallErrorTimeout
//     3, // largeErrorRange
//     500, // largeErrorTimeout
//     5 // slew rate
// };
 
// // turning PID
// lemlib::ChassisController_t angularController {
//     4, // kP
//     40, // kD
//     1, // smallErrorRange
//     100, // smallErrorTimeout
//     3, // largeErrorRange
//     500, // largeErrorTimeout
//     40 // slew rate
// };
 
// // create the chassis
// lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);