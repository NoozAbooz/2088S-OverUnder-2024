/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Declare subsystems for use in other files
 */

#pragma once

#include "main.h"
#include "lemlib/api.hpp"
#include "pros/adi.hpp"

//-- Booleans //--
extern bool cataLoaded;

// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::MotorGroup leftSide;
extern pros::MotorGroup rightSide;

extern lemlib::Chassis chassis;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapultLeft;

// Expansion
extern pros::Motor expansion;

// Inertial
extern pros::Imu inertial;

// Cata Sensor
extern pros::ADIAnalogIn cataPosition;

// LED
extern pros::ADILed bodyLED;