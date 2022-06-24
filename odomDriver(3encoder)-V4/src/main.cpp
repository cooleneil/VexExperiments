/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\neilj                                            */
/*    Created:      Sat Jun 18 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include <math.h>

using namespace vex;

// A global instance of competition
competition Competition;
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2
// Controller1          controller
// leftEncoder          encoder       E, F
// rightEncoder         encoder       G, H
// backEncoder          encoder       C, D
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// absolute x cordinate of the robot
double X = 0.00;
// absolute y cordinate of the robot
double Y = 0.00;
// ablsoute heading of the robot
double Theta = 0;
double wheelRadius = 2;
double Ss = 7;
double Sl = 3.59;
double Sr = 3.59;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

void usercontrol(void) {
  // variable declarations that dont need to be updated in the while loop
  //reset all variables
  double Dx = 0.00;
  double Dy = 0.00;
  double DTx = 0.00;
  double DTy = 0.00;
  double DTheta = 0.00;
  
  double leftEncoderValue = 0;
  double rightEncoderValue = 0;
  double backEncoderValue = 0;
  double Dl = 0.00;
  double Dr = 0.00;
  double Ds = 0.00;
  double currentLeftEncoderValue = 0.00;
  double currentRightEncoderValue = 0.00;
  double currentBackEncoderValue = 0.00;
  double deltaLeftEncoderValue = 0.00;
  double deltaRightEncoderValue = 0.00;
  double deltaBackEncoderValue = 0.00;
  double ThetaM = 0.00;
  double avgLinearDistance = 0;



  while (true) {

    // updates the encoder variables from the encoders. updates the position of
    // the encoder after the wait
    leftEncoderValue = leftEncoder.position(degrees);
    rightEncoderValue = rightEncoder.position(degrees);
    backEncoderValue = backEncoder.position(degrees);
    // calculating the deltas of the raw encoder values
    deltaLeftEncoderValue =
        leftEncoderValue -
        currentLeftEncoderValue; // leftEncoderValue++ represnts value coming
                                 // from encoder
    
    deltaRightEncoderValue = rightEncoderValue - currentRightEncoderValue;

    deltaBackEncoderValue = backEncoderValue - currentBackEncoderValue;
     printf("printing backEncoderValue");
    printf("%f\n", backEncoderValue);
     printf("printing currentBackEncoderValue");
    printf("%f\n", currentBackEncoderValue);
    // making the degrees into radians and multiplying it by the radius
    Dl = ((deltaLeftEncoderValue * 3.1415) / 180) * wheelRadius;
    Dr = ((deltaRightEncoderValue * 3.1415) / 180) * wheelRadius;
    Ds = ((deltaBackEncoderValue * 3.1415) / 180) * wheelRadius;
    printf("printing Ds");
    printf("%f\n", Ds);
    // calculating delta theta
    DTheta = (Dl - Dr) / (Sl + Sr);

    avgLinearDistance = (Dr + Dl) / 2;
    if (DTheta == 0) {
      // moving without turn
      Dy = (Dr + Dl) / 2;
      Dx = Ds;
      
    } else {
      // change x anf y cordinates to match rotation(x and y change if angle is
      // 45 degrees)
      Dx = ((2 * sin(DTheta / 2))) * ((Ds / DTheta) + Ss);
      Dy = ((2 * sin(DTheta / 2))) * ((Dr / DTheta) + Sr);
      
    }
printf("printing Dx");
    printf("%f\n", Dx);
    // calculate average orientation
    ThetaM = Theta + (DTheta / 2);
printf("printing ThetaM");
    printf("%f\n", ThetaM);
    // Rotate the coordinates by -thetaM
    DTx = -Dx * ((cos(ThetaM))) + Dy * ((sin(ThetaM)));
    DTy = Dx * ((sin(ThetaM))) + Dy * ((cos(ThetaM)));
printf("printing DTx");
    printf("%f\n", DTx);
    // update absolute values
    X = X + DTx;
    Y = Y + DTy;
    
    Theta = Theta + DTheta;
    printf("printing X");
    printf("%f\n", X);
    // print values on brain display

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(3, 3);
    Brain.Screen.print(X);
    Brain.Screen.setCursor(3, 20);
    Brain.Screen.print(Y);
    Brain.Screen.setCursor(5, 3);
    Brain.Screen.print(Theta);
    Brain.Screen.setCursor(5, 20);
    Brain.Screen.print(Dx);
    Brain.Screen.setCursor(7, 3);
    Brain.Screen.print(Dy);
    Brain.Screen.setCursor(9, 20);
    Brain.Screen.print(backEncoderValue);
    Brain.Screen.setCursor(9, 3);
    Brain.Screen.print(leftEncoderValue);
    // reset delta

    // waiting 50 msec for the encoders to move and rotate again
    currentLeftEncoderValue = leftEncoder.position(degrees);
    currentRightEncoderValue = rightEncoder.position(degrees);
    currentBackEncoderValue = backEncoder.position(degrees);

    wait(20, msec);
  }
}
void Point2Point(void) {
  printf("function is running\n");
  //variable declarations
  double finalX = 20;
  double finalY = 20;
  double xDisTraveled = finalX - X;
  double yDisTraveled = finalY - Y;
  //calculating the distance needed to move and the angle needed
  double DistanceToFinalPoint =  (sqrt((pow(xDisTraveled, 2)) + (pow(yDisTraveled, 2))));
  printf("%f\n", DistanceToFinalPoint);
  double angleNeeded = (acos(xDisTraveled / DistanceToFinalPoint));
  double LeftValue = 0;
  double RightValue = 0;
  double LeftDistance = 0;
  double RightDistance = 0;
  double lastRightEncoder = 0;
  double lastLeftEncoder = 0;
  double deltaLeft = 0;
  double deltaRight = 0;  
  printf("%f\n", angleNeeded);
  int motorPower = 20;
//doing the turn move command
  while ((angleNeeded - Theta) > 0.05 || (angleNeeded - Theta) < - 0.05 ) {

    if (angleNeeded < Theta) {
front_l.setVelocity(motorPower, pct);
front_r.setVelocity(motorPower, pct);
     front_l.spin(fwd);
      front_r.spin(reverse);
    } else {
      front_l.setVelocity(motorPower, pct);
      front_r.setVelocity(motorPower, pct);
      front_l.spin(reverse);
      front_r.spin(fwd);
    }
    //wait(10, msec);
    //printf("%f\n", Theta);

  }
  //doing the move forward command
  while ((DistanceToFinalPoint - (LeftDistance + RightDistance) / 2) > 1) {
LeftValue = leftEncoder.position(degrees);
RightValue = rightEncoder.position(degrees);

 deltaLeft = lastLeftEncoder - LeftValue;
    deltaRight = lastRightEncoder - RightValue;
    LeftDistance = LeftDistance +((  deltaLeft* 3.1415) / 180 * wheelRadius);
    RightDistance = RightDistance + ((deltaRight* 3.1415) / 180 * wheelRadius);
    lastLeftEncoder = LeftValue;
    lastRightEncoder = RightValue;
    
    if ((DistanceToFinalPoint - (LeftDistance + RightDistance) / 2) < 1.5) {
      front_l.setVelocity(motorPower/2, pct);
      front_r.setVelocity(motorPower/2, pct);
      front_l.spin(fwd);
      front_r.spin(fwd);
      printf("if loop working\n");
    } else {
      front_l.setVelocity(motorPower, pct);
      front_r.setVelocity(motorPower, pct);
      front_l.spin(fwd);
      front_r.spin(fwd);
      printf("else loop working\n");
    }
  }
  front_l.stop(hold);
  front_r.stop(hold);
}

int main() {
  // Run the pre-autonomous function.
  pre_auton();
    Competition.drivercontrol(usercontrol);

Point2Point();
  // Set up callbacks for autonomous and driver control periods.
  //Point2Point();


  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

void joyStickControl(void) {
  double first_val = Controller1.Axis3.position();
  double second_val = Controller1.Axis2.position();
  double leftmotorpower = pow(first_val, 3) / 10000;

  double rightmotorpower = pow(second_val, 3) / 10000;
  if (abs(Controller1.Axis3.position()) > 10 |
      abs(Controller1.Axis2.position()) > 10) {

    front_l.spin(fwd, leftmotorpower, pct);
    front_r.spin(fwd, -rightmotorpower, pct);
  }
}
