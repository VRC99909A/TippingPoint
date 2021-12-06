#include "main.h"

/**auton function for scoring on goal on bridge**/
void LeftOne(){
  //put front claw up and score ring with lever
  Claw(300.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(20);
}

/**auton function for scoring on goal on bridge**/
void LeftTwo(){
  //front claw goes up to score ring with lever
  Claw(300.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceClawGoal(5));
  pros::delay(2000);
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
  pros::delay(2000);
  //drive backward slowly into home zone
  Drive(-1300.0, 25);
}

void RightOne() {
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

}

/**auton function for taking mobile goal out of triangle & scoring**/
void RightTwo() {
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





/**varirables and functions array for auton selector**/
int autonselector = 0;
//define and initialize string array "titles[]" as constant
const char *titles[] = {"LeftOne", "LeftTwo", "RightOne", "RightTwo", "BothOne", "BothTwo", "SkillsAuton"};

//define and initialize an array of function pointers for all auton functions
void (*scripts[])() = {&LeftOne, &LeftTwo, &RightOne, &RightTwo, &BothOne, &BothTwo, &SkillsAuton};

//define auton script runner function - run the selected auton script through on screen "autonselector"
void LCDScriptExecute() {scripts[autonselector]();}
