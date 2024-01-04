#pragma once

/* Libaries */
// LemLib
#include "lemlib/api.hpp"

// Robodash
#include "robodash/api.h"
extern rd::Selector selector;
extern rd::Console console;
extern rd::Image logo;

// Sylib
#include "sylib/sylib.hpp"

// gif-pros
//#include "gif-pros/gifclass.hpp"

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