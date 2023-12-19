#pragma once

/* Libaries */
// LemLib
#include "lemlib/api.hpp"

// Robodash
#include "robodash/api.h"
extern rd::Selector selector;
extern rd::Console console;
extern rd::Image logo;

// gif-pros
//#include "gif-pros/gifclass.hpp"

/* Functions */
// Cata
void refreshCatapult();
void loadCatapult();
void fireCatapult();
extern bool cataLock;

// DT
void arcadeDrive();
double driveCurve(double input, double curve);

// Intake
void refreshIntake();

// Wings
void refreshWings();
void moveWings(bool status);