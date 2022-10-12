/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       Main (Auto & Manual)                                      */
/*    Author:       Michael                                                   */
/*    Created:      Thu Jul 21 2022                                           */
/*    Description:  wenomechainsama                                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// IntakeFront          motor_group   8, 10           
// IntakeStorage        motor         15              
// IntakeTop            motor         16              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void driveForward(int sec, int vel){
  FrontLeft.spin(forward, vel, percent);
  FrontRight.spin(forward, vel, percent);
  BackLeft.spin(forward, vel, percent);
  BackRight.spin(forward, vel, percent);

  wait(sec, seconds);

  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();
}

void turnLeft(int rot, int vel){
  FrontLeft.setVelocity(vel, percent);
  FrontRight.setVelocity(vel, percent);
  BackLeft.setVelocity(vel, percent);
  BackRight.setVelocity(vel, percent);

  FrontLeft.spinFor(reverse, rot, turns, false);
  FrontRight.spinFor(forward, rot, turns, false);
  BackLeft.spinFor(reverse, rot, turns, false);
  BackRight.spinFor(forward, rot, turns);
}

void driveBackward(int sec, int vel){
  FrontLeft.spin(reverse, vel, percent);
  FrontRight.spin(reverse, vel, percent);
  BackLeft.spin(reverse, vel, percent);
  BackRight.spin(reverse, vel, percent);

  wait(sec, seconds);

  FrontLeft.stop();
  FrontRight.stop();
  BackLeft.stop();
  BackRight.stop();
}

void autonomous(void) {
  driveForward(2, 100);  

  IntakeTop.setVelocity(100, percent);
  IntakeFront.setVelocity(100, percent);
  IntakeStorage.setVelocity(100, percent);

  IntakeTop.spinFor(reverse, 2, turns, false);
  IntakeStorage.spinFor(forward, 2, turns);

  //IntakeFront.spinFor(forward, 1, turns, false);
  //IntakeStorage.spinFor(forward, 1, turns);

  driveBackward(1, 80);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Init driveMode var and set motor brake modes
  int driveMode = 1;
  IntakeFront.setStopping(brake);
  IntakeStorage.setStopping(hold);
  IntakeTop.setStopping(brake);  

  //FrontLeft.setStopping(brake);
  //FrontRight.setStopping(brake);
  //BackLeft.setStopping(brake);
  //BackRight.setStopping(brake);

  // Main forever loop
  while(true){

    // Toggle drive mode
    if(Controller1.ButtonX.pressing()){
      waitUntil(!Controller1.ButtonX.pressing());
      if(driveMode == 1){
        driveMode = 0;

        Controller1.rumble(rumbleShort);

        Controller1.Screen.newLine(); 
        Controller1.Screen.print("Driving DISENGAGED      ");
      } else if(driveMode == 0) {
        driveMode = 1;

        Controller1.rumble(rumbleShort); 

        Controller1.Screen.newLine(); 
        Controller1.Screen.print("Driving ENGAGED    ");
      }
    }

    // Get varible power based on joystick position
    int leftPower = Controller1.Axis1.position(percent) + Controller1.Axis3.position(percent);
    int rightPower = Controller1.Axis1.position(percent) - Controller1.Axis3.position(percent);

    // Main motor functions (only works if drivemode is on)
    if(driveMode == 1){
      // Spin motors using power values reduced by modifier
      FrontLeft.spin(forward, leftPower, percent);
      FrontRight.spin(reverse, rightPower, percent);
      BackLeft.spin(forward, leftPower, percent);
      BackRight.spin(reverse, rightPower, percent);

      // Suck Balls 😏🤤😈
      if(Controller1.ButtonR1.pressing()){
        IntakeFront.spin(forward, 100, percent);
        IntakeStorage.spin(forward, 100, percent);

        Controller1.Screen.newLine(); 
        Controller1.Screen.print("Sucking Balls... :)   ");
      } else if(Controller1.ButtonR2.pressing()) {
        IntakeFront.spin(reverse, 100, percent);
        IntakeStorage.spin(reverse, 100, percent);
   
        Controller1.Screen.newLine(); 
        Controller1.Screen.print("Ejecting Balls... T-T   ");

      } else if(Controller1.ButtonL1.pressing()){
        IntakeTop.spin(reverse, 100, percent);

        Controller1.Screen.newLine(); 
        Controller1.Screen.print("[TOP] Ejecting Ball   ");
      } else if(Controller1.ButtonL2.pressing()) {
        IntakeTop.spin(forward, 100, percent);

        Controller1.Screen.newLine(); 
        Controller1.Screen.print("[TOP] Sucking Ball   ");
      //} else if (Optical.hue() > 160 && Optical.hue() < 236){
      //  IntakeFront.spin(forward,100,percent);
      //} else if (Optical.hue() > 0 && Optical.hue() < 40){
      //  IntakeFront.spin(forward,100,percent);
      } else {
        IntakeFront.stop();
        IntakeStorage.stop();
        IntakeTop.stop();
      }
    }

  // Don't wait resources or smth
  wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
