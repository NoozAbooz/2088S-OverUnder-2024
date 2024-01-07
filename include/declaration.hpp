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
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

extern lemlib::Chassis chassis;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor slapper;

// Inertial
extern pros::Imu inertial;

// LED
extern pros::ADILed bodyLED;

extern pros::ADIDigitalOut wingsPiston;

/* Functions */
// Slapper
void refreshSlapper();

// DT
void arcadeDrive();
double driveCurve(double input, double curve);

// Intake
void refreshIntake();

// Wings
void refreshWings();
void moveWings(bool status);