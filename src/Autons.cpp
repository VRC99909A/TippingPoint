#include "main.h"

/**auton function for scoring on goal on bridge**/
void left(){
  //drive out to hit mobile goal
  Drive(50.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //ring falls into mobile goal & back out
  Drive(-50.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}


/**auton function for taking mobile goal out of triangle & scoring**/
void right() {
  //put back claw down
  Claw(-800.0, 100);
  pros::delay(500);
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
  Claw(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //pick up neutral mobile goal
  //drive back into home zone
  Drive(-10000.0, 25);
}




void both(){
  //drive out to hit mobile goal
  Drive(50.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //ring falls into mobile goal & back out
  Drive(-50.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //rotate away from goal
  Rotate(-90.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //re-align with wall
  Drive(-50.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive out a bit
  Drive(150.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //rotate so back is toward right side of field
  Rotate(-90.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //put back claw down
  BackClaw(-200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(5));
  pros::delay(20);
  //drive towards mobile goal in triangle
  Drive(-400.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);

  //use back claw to lift mobile goal up
  BackClaw(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(5));
  pros::delay(20);
  //deposit preload from roller onto mobile goal
  Lift(150.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceLiftGoal(5));
  pros::delay(20);
  //drive back to get out of triangle zone
  Drive(50.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}

void none(){

}

void Neutral(){
  //drive out to hit netural mobile goal
  Drive(300.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //use claw to lift mobile goal up
  Claw(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //drive back
  Drive(-250.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);


}





/**varirables and functions array for auton selector**/
int autonselector = 0;
//define and initialize string array "titles[]" as constant
const char *titles[] = {"left", "right", "both", "none", "Neutral", "SkillsAuton"};

//define and initialize an array of function pointers for all auton functions
void (*scripts[])() = {&left, &right, &both, &none, &Neutral, &SkillsAuton};

//define auton script runner function - run the selected auton script through on screen "autonselector"
void LCDScriptExecute() {scripts[autonselector]();}
