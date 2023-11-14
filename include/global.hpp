/* Libaries */
// gif
#include "gif-pros/gifclass.hpp"

// LemLib
//#include "lemlib/api.hpp"

/* Physical Devices */
// Controller
extern pros::Controller controller;

// Drivetrain
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

// Intake
extern pros::Motor intake;

// Catapult
extern pros::Motor catapult;

// Pneumatics
extern pros::adi::Pneumatics intakePiston;
extern pros::adi::Pneumatics wingPiston;

// LED
extern pros::adi::Led leftLED;
extern pros::adi::Led rightLED;

/* Sensors */
// Inertial
extern pros::Imu inertial;

// Cata Sensor
extern pros::adi::AnalogIn cataLineSensor;
extern pros::adi::DigitalIn cataLimitSwitch;

// Tracking Wheel
extern pros::adi::Encoder trackingWheel;

/* Functions */
void spinIntake();

void refreshCatapult();
void loadCatapult();
void fireCatapult();

void refreshWings();

double driveCurve(double input, double curve);

void cycleGradient(pros::adi::Led& led, std::string color1, std::string color2, int speed);
uint32_t blend(uint32_t color1, uint32_t color2, uint8_t blendAmount);