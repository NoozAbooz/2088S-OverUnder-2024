/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Declare subsystems for use in other files
 */

#pragma once

#include "main.h"
#include "lemlib/api.hpp"
#include "sylib/sylib.hpp"

//-- Booleans //--
extern bool cataLoaded;

// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::Motor frontLeft;
extern pros::Motor backLeft;
extern pros::Motor frontRight;
extern pros::Motor backRight;

extern pros::MotorGroup leftSide;
extern pros::MotorGroup rightSide;

extern lemlib::Chassis chassis;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapultLeft;
extern pros::Motor catapultRight;
extern pros::MotorGroup catapult;

// Expansion
extern pros::Motor expansion;

// Inertial
extern pros::Imu inertial;

// Cata Sensor
extern pros::ADIAnalogIn cataPosition;

// LED
extern sylib::Addrled bodyLED;