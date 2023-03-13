/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Declare subsystems for use in other files
 * @date 2023-03-10
 */

#pragma once

#include "main.h"
#include "lemlib/api.hpp"

// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::Motor frontLeft;
extern pros::Motor midLeft;
extern pros::Motor backLeft;
extern pros::Motor frontRight;
extern pros::Motor midRight;
extern pros::Motor backRight;

extern pros::MotorGroup leftSide;
extern pros::MotorGroup rightSide;

extern lemlib::Chassis chassis;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapult;

// Inertial
extern pros::Imu inertial;

// Cata Sensor
extern pros::ADIAnalogIn cataRot;
