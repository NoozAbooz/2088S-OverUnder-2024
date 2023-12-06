#pragma once
#include "main.h"

/* Libaries */
// LemLib
//#include "lemlib/api.hpp"

// Robodash
#include "robodash/apix.h"
extern rd::Selector selector;
extern rd::Console console;

// gif-pros
//#include "gif-pros/gifclass.hpp"

/* Functions */
// Cata
void refreshCatapult();
void loadCatapult();
void fireCatapult();

// DT
void arcadeDrive();
double driveCurve(double input, double curve);

// Intake
void refreshIntake();

// Wings
void refreshWings();
void moveWings(bool status);

// Auton
void close_wp();