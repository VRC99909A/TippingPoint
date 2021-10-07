#include "main.h"

/**auton function for RED side CLOSE to goal zone**/
void RedGoalSide() {
  Drive(100.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(1000.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(59));
  pros::delay(20);
  Lift(-800.0, 100);
  do{
    pros::delay(20);
    Claw(-10.0, 100);
  }while(!AtDistanceLiftGoal(59));
}



/**auton function for RED side FAR from goal zone**/
void RedFarSide() {
  Drive(100.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);

  Lift(1000.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(59));
  pros::delay(20);

  Lift(-800.0, 75);
  do{
    pros::delay(20);
    Claw(-10.0, 100);
  }while(!AtDistanceLiftGoal(59));
}
void Redbasic(){
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(600.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Lift(-400.0, 75);
  do{
    pros::delay(20);
    Claw(-10.0, 100);
  }while(!AtDistanceLiftGoal(100));
  pros::delay(500);
  Drive(190.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(-200.0, 100);
  pros::delay(1000);
  Lift(600.0, 100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Rotate(-285.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(700.0, 50);
  Lift(-400.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(-400.0, 100);
  pros::delay(500);
  Lift(500.0, 50);
  do {
    pros::delay(20);
    Claw(-10.0, 50);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Rotate(-200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(450.0, 75);
  pros::delay(650);
  //Rotate(75.0, 100);
  //Drive(200.0, 75);
  pros::delay(500);
  Drive(-50.0, 100);
  Rotate(50.0, 100);
  Lift(-500.0, 75);
  pros::delay(1000);
  //pros::delay(5000);
  Claw(300.0, 100);
  pros::delay(500);
  //pros::delay(5000);
  //Lift(500.0, 50);
  //do {
  //  pros::delay(20);
  //} while (!AtDistanceLiftGoal(100));
  //pros::delay(20);
  Drive(-500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Claw(-300.0, 100);
  Lift(400.0, 100);
  pros::delay(100);
}

void Bluebasic(){
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(600.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Lift(-400.0, 75);
  do{
    pros::delay(20);
    Claw(-10.0, 100);
  }while(!AtDistanceLiftGoal(100));
  pros::delay(500);
  Drive(190.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(-200.0, 100);
  pros::delay(1000);
  Lift(600.0, 100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Rotate(285.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(700.0, 50);
  Lift(-400.0, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(-400.0, 100);
  pros::delay(500);
  Lift(500.0, 50);
  do {
    pros::delay(20);
    Claw(-10.0, 50);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Rotate(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(450.0, 75);
  pros::delay(650);
  //Rotate(75.0, 100);
  //Drive(200.0, 75);
  pros::delay(500);
  Drive(-50.0, 100);
  Rotate(-50.0, 100);
  Lift(-500.0, 75);
  pros::delay(1000);
  //pros::delay(5000);
  Claw(300.0, 100);
  pros::delay(500);
  //pros::delay(5000);
  //Lift(500.0, 50);
  //do {
  //  pros::delay(20);
  //} while (!AtDistanceLiftGoal(100));
  //pros::delay(20);
  Drive(-500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Claw(-300.0, 100);
  Lift(400.0, 100);
  pros::delay(100);
}

/**auton function for BLUE side CLOSE to goal zone**/
void BlueGoalSide(){
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(600.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Lift(-400.0, 100);
  do{
    pros::delay(20);
    Claw(-10.0, 100);
  }while(!AtDistanceLiftGoal(100));
  Drive(200.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(-200.0, 100);
  pros::delay(1000);
  Lift(600.0, 100);
  pros::delay(1000);
  Drive(450.0, 25);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(500);
  Lift(-550.0, 20);
  pros::delay(2000);
  Claw(200.0, 100);
  pros::delay(500);
  Lift(-250.0, 50);
  pros::delay(1000);
  Claw(-200.0, 100);
  pros::delay(500);
  Drive(-1000.0, 100);
  pros::delay(1500);
  Drive(100.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Rotate(400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(750.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(-600.0, 20);
  pros::delay(1500);
  Claw(200.0, 100);
  pros::delay(500);
  Lift(300, 50);
  do{
    pros::delay(20);
    Drive(-10, 100);
    Claw(50, 100);
  }while(!AtDistanceLiftGoal(50));
  pros::delay(69);
}



/**auton function for BLUE side FAR from goal zone**/
void BlueFarSide() {
  Drive(100.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);

  Lift(1000.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(59));
  pros::delay(20);
  Lift(-800.0, 100);
  do{
    pros::delay(20);
    Claw(-10.0, 100);
  }while(!AtDistanceLiftGoal(59));
}



//Basic auto function
void basic(){
  Drive(-800, 100);
  pros::delay(2000);
  Drive(1000, 100);
  pros::delay(2000);
  Lift(800.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-10.0, 100);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Lift(-600.0, 100);
  do{
    pros::delay(20);
    Claw(-10.0, 100);
  }while(!AtDistanceLiftGoal(100));
  Lift(-250.0, 100);
  pros::delay(500);
  Claw(50.0, 100);
  pros::delay(250);
  Lift(300.0, 100);
  do{
    pros::delay(20);
    Claw(10.0, 100);
    Drive(-20.0, 100);
  }while(!AtDistanceLiftGoal(100));
}


/**varirables and functions array for auton selector**/
int autonselector = 0;
const char *titles[] = {"Redbasic", "bluebasic", "basic", "RedGoalSide", "RedFarSide", "BlueGoalSide", "BlueFarSide", "SkillsAuton"};

void (*scripts[])() = {&Redbasic, &Bluebasic, &basic, &RedGoalSide, &RedFarSide, &BlueGoalSide, &BlueFarSide, &SkillsAuton};

void LCDScriptExecute() {scripts[autonselector]();}
