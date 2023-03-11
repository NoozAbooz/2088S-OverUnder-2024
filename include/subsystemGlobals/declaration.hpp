/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Declare subsystems for use in other files
 * @date 2023-03-10
 */

#include "main.h"

// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::Motor frontLeft;
extern pros::Motor backLeft;
extern pros::Motor frontRight;
extern pros::Motor backRight;

extern pros::MotorGroup leftSide;
extern pros::MotorGroup rightSide;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapult;

// Inertial
extern pros::Imu inertial;

// Cata Rotation
extern pros::ADIDigitalIn cataRot;