#include "main.h"

/* Physical Devices */
// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::MotorGroup leftSide;
extern pros::MotorGroup rightSide;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapult;

// Pneumatics
extern pros::adi::Pneumatics intakePiston;
extern pros::adi::Pneumatics leftWing;
extern pros::adi::Pneumatics rightWing;

// LED
extern pros::adi::Led bodyLED;

/* Sensors */
// Inertial
extern pros::Imu inertial;

// Cata Sensor
extern pros::adi::AnalogIn cataPosition;

// Tracking Wheel
extern pros::adi::Encoder trackingWheel;

/* Functions */
void spinIntake();

void refreshCatapult();
void loadCatapult();
void fireCatapult();