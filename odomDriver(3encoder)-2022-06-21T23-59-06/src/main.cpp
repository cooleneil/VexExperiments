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

#include "vex.h"

using namespace vex;

void pre_auton(void){
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}
  void usercontrol(void){
  double wheelRadius = 2;
        double Ss = 6.25;
        double Sl = 3.5;
        double Sr = 3.5;
        double X = 0.00;
        double Y = 0.00;
      //  double currentX = 0.00;
      //  double currentY = 0.00;
        double Theta = 0;
        double Dx = 0.00;
        double Dy = 0.00;
        
        double DTx = 0.00;
        double DTy = 0.00;
        double DTheta = 0.00;
        double leftEncoderValue = leftEncoder.position(degrees);
        double rightEncoderValue = rightEncoder.position(degrees);
        double backEncoderValue = backEncoder.position(degrees);
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
        double ThetaR = 0;


            while (true)
            {
                leftEncoderValue = leftEncoder.position(degrees);
                rightEncoderValue = rightEncoder.position(degrees);
                backEncoderValue = backEncoder.position(degrees);
                deltaLeftEncoderValue =  leftEncoderValue - currentLeftEncoderValue;//leftEncoderValue++ represnts value coming from encoder
                currentLeftEncoderValue = currentLeftEncoderValue + deltaLeftEncoderValue;

                deltaRightEncoderValue = rightEncoderValue - currentRightEncoderValue;
                currentRightEncoderValue = currentRightEncoderValue + deltaRightEncoderValue;

                deltaBackEncoderValue = backEncoderValue - currentBackEncoderValue;
                currentBackEncoderValue = currentBackEncoderValue + deltaBackEncoderValue;

                Dl = ((deltaLeftEncoderValue * 3.1415) / 180) * wheelRadius;
                Dr = ((deltaRightEncoderValue * 3.1415) / 180) * wheelRadius;
                Ds = ((deltaBackEncoderValue * 3.1415) / 180) * wheelRadius;

                DTheta = (Dl - Dr) / (Sl + Sr);

                
                if (DTheta == 0)
                {
                    //moving without turn
                   Dx =  Ds;
                   Dy = Dr;
 
                }
                else
                {
                   Dx =  ((2 *sin(DTheta/2))) * ((Ds / DTheta) + Ss);
                    Dy = ((2 *sin(DTheta/2))) * ((Dr / DTheta) + Sr);
                     
                }

                    //calculate average orientation
                    ThetaM = Theta + (DTheta / 2); 
                     
                    // Rotate the coordinates by -thetaM
                    DTx = Dx * ((cos(-ThetaM))) - Dy * ((sin(-ThetaM))); 
                    DTy = Dx * ((sin(-ThetaM))) - Dy * ((cos(-ThetaM)));

                    //update absolute values 
                    X = X + DTx;
                    Y = Y + DTy;
                    Theta = Theta + DTheta;
            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(3,3);
    Brain.Screen.print(X);
      Brain.Screen.setCursor(3,20);
    Brain.Screen.print(Y);
    Brain.Screen.setCursor(5,3);
    Brain.Screen.print(Theta);
    Brain.Screen.setCursor(5,20);
    Brain.Screen.print(ThetaM);
      Brain.Screen.setCursor(7,3);
     Brain.Screen.print(DTheta);
      Brain.Screen.setCursor(9,20);
      Brain.Screen.print(Dl);
      Brain.Screen.setCursor(9,3);
      Brain.Screen.print(Dr);
            //reset delta
       


          wait(50, msec);
      
     
            } 
  }
   
   int main() {
    // Set up callbacks for autonomous and driver control periods.
    
    Competition.drivercontrol(usercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Prevent main from exiting with an infinite loop.
    while (true) {
      wait(100, msec);
    }
   
   }
