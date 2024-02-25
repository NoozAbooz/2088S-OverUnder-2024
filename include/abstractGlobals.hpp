#pragma once

// 3rd party libraries
#include "lemlib/api.hpp"
//#include "sylib/sylib.hpp"
#include "gif-pros/gifclass.hpp"
#include "Graphy/Grapher.hpp"

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