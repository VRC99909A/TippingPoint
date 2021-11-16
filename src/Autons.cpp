#include "main.h"

/**auton function for scoring on goal on bridge**/
void left(){
  //put front claw down and score ring with lever
  Claw(-500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //Drive towards mobile goal
  Drive(1300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //use claw to get neutal mobile goal
  Claw(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //drive backward slowly
  Drive(-1300.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
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
  //put front claw down and score ring with lever
  Claw(-500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //Drive straight till middle
  Drive(1300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //Rotate so back claw faces mobile goal in WPZ
  Rotate(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(750);
  //Drive till reach goal in WPZ
  Drive(-1600.0, 100);
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

void none(){

}

void NeutralBoth(){
  //put front claw down and score ring with lever
  Claw(-500.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
  //Drive towards mobile goal
  Drive(1300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);
  //use claw to get neutal mobile goal
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
  Rotate(300.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(750);
  //Drive till reach goal in WPZ
  Drive(-1600.0, 100);
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





/**varirables and functions array for auton selector**/
int autonselector = 0;
//define and initialize string array "titles[]" as constant
const char *titles[] = {"left", "right", "both", "none", "NeutralBoth", "SkillsAuton"};

//define and initialize an array of function pointers for all auton functions
void (*scripts[])() = {&left, &right, &both, &none, &NeutralBoth, &SkillsAuton};

//define auton script runner function - run the selected auton script through on screen "autonselector"
void LCDScriptExecute() {scripts[autonselector]();}
