#include "main.h"

/**auton function for scoring on goal on bridge**/
void left(){
  //drive out to hit mobile goal
  Drive(25.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //ring falls into mobile goal
}


/**auton function for taking mobile goal out of triangle & scoring**/
void right() {
  //drive out a bit
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //rotate toward mobile goal
  Rotate(45.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive forward until reach mobile goal
  Drive(100.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //use claw to lift mobile goal up
  Claw(200.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //deposit preload from roller onto mobile goal
  Lift(150.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive back to get out of triangle zone
  Drive(-50.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}




void both(){
  //drive out to hit mobile goal
  Drive(25.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //ring falls into mobile goal
  //rotate away from goal
  Rotate(-90.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //re-align with wall
  Drive(-25.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive out a bit
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //rotate toward right side of field
  Rotate(90.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive towards mobile goal in triangle
  Drive(250.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);

  //rotate toward mobile goal
  Rotate(45.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive forward until reach mobile goal
  Drive(100.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //use claw to lift mobile goal up
  Claw(200.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //deposit preload from roller onto mobile goal
  Lift(150.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //drive back to get out of triangle zone
  Drive(-50.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
}

void none(){

}



/**varirables and functions array for auton selector**/
int autonselector = 0;
//define and initialize string array "titles[]" as constant
const char *titles[] = {"left", "right", "both", "none", "SkillsAuton"};

//define and initialize an array of function pointers for all auton functions
void (*scripts[])() = {&left, &right, &both, &none, &SkillsAuton};

//define auton script runner function - run the selected auton script through on screen "autonselector"
void LCDScriptExecute() {scripts[autonselector]();}
