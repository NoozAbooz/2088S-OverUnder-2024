#pragma once

// 3rd party libraries
#include "sylib/sylib.hpp"
#include "lemlib/api.hpp"
#include "gif-pros/gifclass.hpp"
#include "gif-pros/asset.h"

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