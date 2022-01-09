#include "main.h"

/**auton function for scoring on goal on bridge**/
void LeftOne(){
  //front claw goes up to score ring with lever
  Claw(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  //pros::delay(200);
  //open snap up
  Snap(-150.0, 75);
  //do {
  //  pros::delay(20);
  //} while (!AtDistanceSnapGoal(5));
  //pros::delay(200);
  //put front claw down
  Claw(-375.0, 100);
  //Drive towards mobile goal
  Drive(1550.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  //pros::delay(500);
  //use snap to get neutal mobile goal
  //Drive(175.0, 25);
  Snap(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  //pros::delay(500);
  //drive backward slowly into home zone
  Drive(-1300.0, 100);
}



/**auton function for scoring on goal on bridge**/
void LeftTwo(){
  //front claw goes up to score ring with lever
  /**
  Claw(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(400);
  //open snap up
  Snap(-250.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(200);
  //put front claw down
  Claw(-375.0, 100);
  //Drive towards mobile goal
  Drive(1550.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(500);
  //use snap to get neutal mobile goal
  Drive(175.0, 25);
  Snap(600.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(20);
  //drive backward slowly into home zone
  Claw(200.0, 100);
  Drive(-300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(20);
  RotateDegreesLeft(90);
  Drive(-600.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(20);
  RotateDegreesLeft(45);
  Drive(-300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(20);
  BackClaw(370.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(5));
  pros::delay(20);
  Drive(1000.0, 100);
  **/
  Claw(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  //open snap up
  Snap(-150.0, 75);
  BackClaw(370.0, 100); //lift BackClaw


  //put front claw down
  Claw(-375.0, 100);

  //Drive towards mobile goal
  Drive(1550.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //use snap to get neutal mobile goal
  Snap(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));

  pros::delay(500);

  //back up a little
  Drive(-150.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(350.0, 100); //turn left
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  BackClaw(-370.0, 100); //lower backclaw
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500); //allow time for the backclaw to lift up


  //back up a little
  Drive(-300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(50.0, 100); //continue turning left
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //back towards middle tall goal
  Drive(-400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //lift backclaw to capture middle tall goal
  BackClaw(370.0, 100); //lift BackClaw to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500); //allow time for the backclaw to lift up

  Rotate(150.0, 100); //turn left
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //drive towards home zone
  Drive(1500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

}



void RightOne() {
  /**
  //put back claw down
  Claw(500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //put front claw back down
  Claw(-500.0, 75);
  //drive toward mobile goal
  Drive(-750.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //use claw to lift mobile goal up
  BackClaw(370.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500);
  //deposit preload from roller onto mobile goal
  Lift(-500.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceLiftGoal(5));
  pros::delay(20);
  //drive back
  Drive(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  **/

  Claw(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));

  Snap(-150.0, 75);

  Claw(-375.0, 100);
  //Drive towards mobile goal
  Drive(1550.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Snap(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));


  Drive(-300, 100);//pull back a little
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(150.0, 100); //turn left 35 degree to capture the alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-700, 80);//drive backwards to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  BackClaw(370.0, 100); //lift BackClaw to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500); //allow time for the backclaw to lift up

  LiftMotor.move_voltage(-10000); //run ring belt

  Rotate(-150.0, 100); //turn right 35 degree to straighten up
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-600, 80);//drive backwards to home zone
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  LiftMotor.move_voltage(0);
}



/**auton function for taking mobile goal out of triangle & scoring**/
void RightTwo() {
  //put back claw down
  /**
  Claw(500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //put front claw back down
  Claw(-500.0, 75);
  //drive toward mobile goal
  Drive(-750.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //use claw to lift mobile goal up
  BackClaw(370.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500);
  //deposit preload from roller onto mobile goal
  Lift(-500.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceLiftGoal(5));
  pros::delay(20);
  //rotate to make front face neutral goal
  Drive(400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Rotate(390.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive to reach neutral mobile goal
  Drive(400.0, 100);
  pros::delay(1000);
  Drive(-400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Rotate(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(750);
  Drive(1000.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  Snap(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(20);
  //pick up neutral mobile goal
  //drive back into home zone
  Drive(-10000.0, 25);
  **/
  Claw(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));

  Snap(-150.0, 75);

  Claw(-375.0, 100);
  //Drive towards mobile goal
  Drive(1550.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Snap(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));

  Rotate(-200.0, 100); //turn right with back facing middle tall goal
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-220, 100);//pull back a little
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(-170.0, 100); //turn right with back facing middle tall goal
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //back towards middle tall goal
  Drive(-400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //lift backclaw to capture middle tall goal
  BackClaw(370.0, 100); //lift BackClaw to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500); //allow time for the backclaw to lift up

  Rotate(-150.0, 100); //turn right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //drive towards home zone
  Drive(1500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));



}



void BothOne(){
  //front claw goes up to score ring with lever
  Claw(300.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //put front claw down
  Claw(-300.0, 50);
  //Drive straight till middle
  Drive(750.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //Rotate so back claw faces mobile goal in WPZ
  Rotate(315.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(750);
  //Drive till reach goal in WPZ
  Drive(-2575.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //use back claw to collect mobile goal
  BackClaw(360.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500);
  //deposit preload from roller onto mobile goal
  Lift(-450.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceLiftGoal(5));
  pros::delay(20);
  //Drive out of WPZ
  Drive(500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);

}



void BothTwo(){
  //front claw goes up to score ring with lever
  Claw(300.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //put front claw down
  Claw(-300.0, 50);
  //Drive towards mobile goal
  Drive(1400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //use snap to get neutral mobile goal
  Snap(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(20);
  //use claw to get neutral mobile goal
  Claw(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //drive backward slowly
  Drive(-500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //Rotate so back claw faces mobile goal in WPZ
  Rotate(325.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(750);
  //Drive till reach goal in WPZ
  Drive(-2500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //use back claw to collect mobile goal
  BackClaw(370.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500);
  //deposit preload from roller onto mobile goal
  Lift(-500.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceLiftGoal(5));
  pros::delay(20);
  //Drive out of WPZ
  Drive(500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
}



void LeftMiddle(){
  /**
  //front claw goes up to score ring with lever
  Claw(300.0, 75);
  Drive(150.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(500);
  Snap(-250.0, 100);
  Claw(-375.0, 100);
  //open snap up
  //put front claw down
  //Drive towards mobile goal
  Drive(950.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  ImuSensor.set_heading(0.0);
  RotateDegreesRight(58.0);
  Drive(1400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);

  //use snap to get neutal mobile goal
  Snap(600.0, 100);
  pros::delay(500);
  Claw(150.0, 50);
  pros::delay(500);
  ImuSensor.set_heading(0.0);
  RotateDegreesLeft(45.0);
  Drive(-10000.0, 50);
  **/

  //front claw goes up to score ring with lever
  Claw(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));

  Snap(-150.0, 75);

  Claw(-375.0, 100);
  //Drive towards mobile goal
  Drive(1100.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(-220.0, 100); //turn right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(750.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(60.0, 100); //turn left towards middle tall goal
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(250.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Snap(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  //pros::delay(500);
  Claw(100.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  //drive backward slowly into home zone
  Drive(-1300.0, 100);

}



//Auton_wreckingBall
void Shell(){
  //front claw goes up to score ring with lever
  Claw(300.0, 100);
  Drive(675.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Claw(-300.0, 75);
  Snap(-250.0, 100);
  Drive(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Claw(400.0, 100);
  Drive(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //open snap up
  //put front claw down
  //Drive towards mobile goal

  //use snap to get neutal mobile goal
  Rotate(350.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(500);
  Drive(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(-200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Rotate(-175.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(-500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Rotate(-350.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Snap(600.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceSnapGoal(5));
  pros::delay(2000);
  //drive backward slowly into home zone
  Claw(150.0, 100);
  Drive(-1300.0, 50);
}





/**varirables and functions array for auton selector**/
int autonselector = 0;
//define and initialize string array "titles[]" as constant
const char *titles[] = {"LeftOne   ", "LeftTwo   ", "LeftMiddle", "RightOne  ", "RightTwo  ", "BothOne   ", "BothTwo   ", "Shell     ", "SkillsOne ", "SkillsTwo "};

//define and initialize an array of function pointers for all auton functions
void (*scripts[])() = {&LeftOne, &LeftTwo, &LeftMiddle, &RightOne, &RightTwo, &BothOne, &BothTwo, &Shell, &SkillsAutonOne, &SkillsAutonTwo};

//define auton script runner function - run the selected auton script through on screen "autonselector"
void LCDScriptExecute() {scripts[autonselector]();}
