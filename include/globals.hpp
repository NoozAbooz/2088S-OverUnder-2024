#pragma once
#include "main.h"

/* Libaries */
// LemLib
//#include "lemlib/api.hpp"

// Robodash
#include "robodash/api.h"
#include "robodash/views/selector.hpp"
extern rd::Selector selector;
extern rd::Console console;

// gif-pros
#include "gif-pros/gifclass.hpp"

/* Physical Devices */
// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapult;

// Pneumatics
extern pros::adi::Pneumatics intakePiston;
extern pros::adi::Pneumatics wingPiston;

// LED
extern pros::adi::Led leftLED;
extern pros::adi::Led rightLED;

/* Sensors */
// Inertial
extern pros::Imu inertial;

// Cata Sensor
extern pros::adi::AnalogIn cataLineSensor;

// Tracking Wheel
extern pros::adi::Encoder trackingWheel;

/* Functions */
// Cata
void refreshCatapult();
void loadCatapult();
void fireCatapult();

// DT
void arcadeDrive();
double driveCurve(double input, double curve);

// Intake
void refreshIntake();

// Wings
void refreshWings();
void toggleWings(bool status);