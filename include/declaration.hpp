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
extern pros::Motor driveMotor;

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
extern pros::ADIDigitalOut liftPiston;

/* Functions */
// Slapper
void refreshSlapper();

// Lift
void refreshLift();

// DT
void arcadeDrive();
double driveCurve(double input, double curve);
void drivetrainMove(int voltage, int time);

// Intake
void refreshIntake();

// Wings
void refreshWings();
void moveWings(bool status);