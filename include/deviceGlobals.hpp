#pragma once
#include "libSTRAITIS/drivetrain/chassis.hpp"
#include "main.h"

// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

extern lemlib::Chassis chassis;
extern strait::chassisConstructor dt;

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
extern pros::ADIDigitalOut tailPiston;