#pragma once
#include "main.h"
#include "pros/imu.hpp"

// Controller
extern pros::Controller controller;

// Drivetrain
// extern pros::MotorGroup leftDrive;
// extern pros::MotorGroup rightDrive;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapult;

// Pneumatics
extern pros::adi::Pneumatics wingPiston;

// LED


/* Sensors */

// Cata Sensor
extern pros::adi::AnalogIn cataLineSensor;

extern pros::Imu inertial;