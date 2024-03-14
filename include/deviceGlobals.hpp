#pragma once
#include "main.h"
#include "pros/adi.hpp"

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
extern pros::Imu inertial2;

// LED
extern pros::ADILed light;
extern pros::ADIPotentiometer potentiometer;

extern pros::ADIDigitalOut wingsPiston;
extern pros::ADIDigitalOut liftPiston;
extern pros::ADIDigitalOut tailPiston;