#pragma once
#include "deviceGlobals.hpp"
#include "main.h"

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


/* Sensors */
// Inertial
extern pros::Imu inertial;

// Cata Sensor
extern pros::adi::AnalogIn cataLineSensor;

// Tracking Wheel
//extern pros::adi::Encoder trackingWheel;

