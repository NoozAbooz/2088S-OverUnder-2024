#pragma once
#include "api.h"

// Controller
inline pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain
// extern pros::MotorGroup leftDrive;
// extern pros::MotorGroup rightDrive;

// Intake
inline pros::Motor intake(-5, pros::v5::MotorGears::blue);

// Slapper
inline pros::Motor slapper(7, pros::v5::MotorGears::red);

// Pneumatics
inline pros::adi::Pneumatics wingPiston('H', false);
inline pros::adi::Pneumatics liftPiston('G', false);

// LED


/* Sensors */

// Inertial
inline pros::Imu inertial(11);