// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       E, F            
// rightEncoder         encoder       G, H            
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// front_L              motor         2
// front_R              motor         1
// leftEncoder          encoder       C, D
// rightEncoder         encoder       E, F
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

// #include "buttons.h"
// #include "robot-config.h"
#include "vex.h"
#include <math.h>

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

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..................................................................
 
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // joyStickControl();
    // double first_val = Controller1.Axis3.position();
    // double second_val = Controller1.Axis2.position();
    // double leftmotorpower = pow(first_val, 3) / 10000;

    // double rightmotorpower = pow(second_val, 3) / 10000;
    // if (abs(Controller1.Axis3.position()) > 10 |
    //     abs(Controller1.Axis2.position()) > 10) {

    //   front_L.spin(fwd, leftmotorpower, pct);
    //   front_R.spin(fwd, -rightmotorpower, pct);
      


double L= 0;
  double xPos = 0.00;
      double yPos = 0.00;
      double XCord = 0.00;
      double YCord = 0.00;
      double R = 0;
      double LDis = 0; 
      double RDis = 0;
      double CDis = 0;
      double headingAngle = 0;
      double headingAngleDelta = 0;
      double deltaL;
      double deltaR;

while (true) {
       double currentL = leftEncoder.position(degrees);
       double currentR = rightEncoder.position(degrees);
       deltaL = currentL - L;
       deltaR = currentR - R;
       L = currentL;
       R = currentR;

      LDis = (deltaL/360)* (4 * 3.1415);
      RDis = (deltaR/360) * (4 * 3.1415);
      
      
        // rotation
        headingAngleDelta = (RDis - LDis)/7;
        CDis = (RDis + LDis)/2;

        // position
        if(headingAngleDelta != 90){
          
        }
        else {
         // yPos = 3.00;
        }
          xPos = -double((sin(headingAngle))) * CDis;
        
        
         // xPos = 2.00;
        

        XCord = XCord + xPos;//X + xPos;
        YCord = YCord + yPos;
        
        headingAngle = headingAngle + headingAngleDelta;
         // Brain.Screen.print("");
          Brain.Screen.clearScreen();
          Brain.Screen.setCursor(3,3);
  Brain.Screen.print(XCord);
    Brain.Screen.setCursor(3,20);
   Brain.Screen.print(xPos);
   Brain.Screen.setCursor(5,3);
   Brain.Screen.print(YCord);
    Brain.Screen.setCursor(5,20);
   Brain.Screen.print(yPos);
   Brain.Screen.setCursor(7,3);
   Brain.Screen.print(L);
   Brain.Screen.setCursor(7,20);
   Brain.Screen.print(R);
   Brain.Screen.setCursor(9,3);
   Brain.Screen.print(headingAngle);
           //reset delta
        xPos = 0;
        yPos = 0;

         headingAngleDelta = 0;

        wait(50, msec);
      } 
    }
  }


  // printf("leftmotor: %lf/n", leftmotorpower);
  // printf("rightmotor: %lf/n", rightmotorpower); // prevent wasted resources.
  // else {
  //   front_L.stop(coast);
  //   front_R.stop(coast);
  // }
  // buttonControl();
  // wait(20, msec); // Sleep the task for a short amount of time to
  // prevent wasted resources.
  //}

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