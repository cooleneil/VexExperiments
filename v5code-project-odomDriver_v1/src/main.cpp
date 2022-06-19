// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       E, F            
// rightEncoder         encoder       G, H            
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       G, H            
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
// Drivetrain           drivetrain    1, 2            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// front_R              motor         1               
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// front_L              motor         2               
// front_R              motor         1               
// leftEncoder          encoder       C, D            
// rightEncoder         encoder       E, F            
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
  // ,lljjlllljk777........ leftside.setVelocity(100, pct);
  // rightside.setVelocity(100, pct);

  // f_bar_a.spinFor(fwd, -20, deg, false);

  // f_bar_b.spinFor(fwd, 20, deg);
  // f_bar_a.stop(hold);
  // f_bar_b.stop(hold);
  // clamp.spinFor(reverse, -385, deg, false);

  // leftside.spinFor(fwd, 1265, deg, false);
  // rightside.spinFor(fwd, -1265, deg);
  // leftside.stop(hold);
  // rightside.stop(hold);
  /*leftside.spinFor(fwd, 1320, deg, false);
  rightside.spinFor(fwd, -1320, deg);
  leftside.stop(hold);
  rightside.stop(hold);*/

  /*float currentPosition = ((back_L.rotation(deg) + back_R.rotation(deg) +
 front_L.rotation(deg) + front_R.rotation(deg)) / 4); float Target = 1320; float
 error = Target - currentPosition;

 float k = -5;
  while (error < Target) {
    currentPosition = ((back_L.rotation(deg) + back_R.rotation(deg) +
 front_L.rotation(deg) + front_R.rotation(deg)) / 4); error = Target -
 currentPosition;

    rightside.spin(reverse, (error * k), volt);
    leftside.spin(fwd, (error * k), volt);
    wait(20, msec);  }*/

  // wait(200, msec);

  // clamp.spinFor(fwd, -220, deg, false);
  // wait(1250, msec);
  // Back Up
  // rightside.spinFor(fwd, 350, deg);
  // rightside.stop(hold);
  // leftside.setVelocity(80, pct);

  // Back up
  // leftside.spinFor(reverse, 780, deg, false);
  // rightside.spinFor(reverse, -780, deg);
  // leftside.setVelocity(30, pct);
  // rightside.setVelocity(30, pct);
  // clamp.spinFor(fwd, 200, deg);

  // leftside.spinFor(reverse, 600, deg, false);
  // rightside.spinFor(reverse, -600, deg);

  // leftside.spinFor(reverse, 117, deg, false);
  // rightside.spinFor(fwd, -117, deg);
  // leftside.spinFor(fwd, 1570, deg, false);
  // //1480
  // rightside.spinFor(fwd, -1570, deg);
  // //leftside.stop(hold);
  // //rightside.stop(hold);
  // /*leftside.setVelocity(70, pct);
  // rightside.setVelocity(70, pct);
  // leftside.spinFor(fwd, 185, deg, false);
  // rightside.spinFor(fwd, -185, deg);*/

  // clamp.spinFor(fwd, -250, deg, false);
  // wait(750, msec);

  // // Back Up
  // //rightside.spinFor(fwd, 350, deg);
  // //rightside.stop(hold);l;]\
  // //leftside.setVelocity(80, pct);
  // leftside.setVelocity(80, pct);
  // rightside.setVelocity(80, pct);
  // //Back up
  // leftside.spinFor(reverse, 1100, deg, false);
  // rightside.spinFor(reverse, -1100, deg);
  // wait(750, msec);
  // Rigght
  /*rightside.spinFor(fwd, 650, deg);
  clamp.spinFor(fwd, -150, deg);

  leftside.spinFor(fwd, -430, deg, false);
  rightside.spinFor(fwd, 430, deg);
  //wait(1000, msec);
  rightside.spinFor(fwd, -900, deg);
  leftside.spinFor(fwd, 755, deg, false);
  rightside.spinFor(fwd, -755, deg);

  leftside.setVelocity(70, pct);
  rightside.setVelocity(70, pct);
  leftside.spinFor(fwd, 45, deg, false);
  rightside.spinFor(fwd, -45, deg);


  clamp.spinFor(fwd, 150, deg);

  leftside.spinFor(fwd, -1100, deg, false);
  rightside.spinFor(fwd, 1100, deg);
  //Left
  //leftside.spinFor(fwd, 1200, deg);

  //
  rightside.spinFor(fwd, 4000, deg);

  leftside.spinFor(fwd, 400, deg, false);
  rightside.spinFor(fwd, -400, deg);

  leftside.spinFor(fwd, 800, deg, false);
  rightside.spinFor(fwd, -800, deg);

  clamp.spinFor(fwd, -150, deg);

  leftside.spinFor(reverse, 800, deg, false);
  rightside.spinFor(reverse, -800, deg);
  rightside.setVelocity(100, pct);
  leftside.setVelocity(100, pct);*/

  // wait(20, msec);
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
      //       while (true) {
      //         float ydisL = 3;//encoder values
      //         float ydisR = 3;//encoder values
      //         float Xdis = 4;//encoder values
      //         float inertialAngle = 60;//heading
      //         bool Fwd = true;
      //         float yPos = 0;//
      //         float xPos = 0;
      //         float X_Position = 0;
      //         float Y_Position = 0;
      //         if (inertialAngle == 0) {
      //           if (Fwd == true) {
      //             yPos == (ydisL + ydisR) / 2;
      //             xPos == Xdis;
      //           } if(inertialAngle == 0) {
      //             if (Fwd == false){
      //             yPos == (ydisL + ydisR) / -2;
      //             xPos == -1 * Xdis;
      //             }
      //           }
      //         }
      //         if( inertialAngle != 0 && (ydisR + ydisL) > 0 ){
      // float yDisTrav = (ydisR + ydisL)/2 ;
      // xPos ==  (double (cos(inertialAngle)))*yDisTrav;
      // yPos == (double (sin(inertialAngle)))*xPos;
      //         }
      // X_Position = X_Position + xPos;
      // Y_Position = Y_Position + yPos;



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
        yPos = double((cos(headingAngle))) * CDis;
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
      wait(1, msec);
    }
  }