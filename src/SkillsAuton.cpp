#include "main.h"


void SkillsAuton(){
  Drive(75.0, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(600.0, 100);
  pros::delay(100);
  do {
    pros::delay(20);
    Claw(-5.0, 100);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Lift(-400.0, 75);
  do{
    pros::delay(20);
    Claw(-5.0, 100);
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
    Claw(-5.0, 100);
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
    Claw(-5.0, 50);
  } while (!AtDistanceLiftGoal(100));
  pros::delay(20);
  Rotate(200.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(300.0, 75);
  pros::delay(650);
  //Rotate(75.0, 100);
  //Drive(200.0, 75);
  pros::delay(500);
  Drive(-50.0, 100);
  Rotate(50.0, 100);
  Lift(-500.0, 75);
  pros::delay(1000);
  //pros::delay(5000);
  Claw(150.0, 100);
  pros::delay(500);
  //pros::delay(5000);
  //Lift(500.0, 50);
  //do {
  //  pros::delay(20);
  //} while (!AtDistanceLiftGoal(100));
  //pros::delay(20);
  Drive(-750.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  //Claw(-300.0, 100);
  Lift(400.0, 100);
  pros::delay(100);
  //yeet
  Rotate(-285.0, 100);
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
  pros::delay(1000);
  Drive(-2000.0, 75);
  pros::delay(2500);
  Drive(800.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Claw(150.0, 100);
  pros::delay(500);
  Lift(-600.0, 50);
  pros::delay(1500);
  Claw(-250.0, 100);
  pros::delay(300);
  Lift(100.0, 100);
  pros::delay(200);
  Rotate(475.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Drive(800.0, 50);
  Lift(500.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Lift(-550.0, 25);
  pros::delay(3000);
  Claw(150.0, 50);
  pros::delay(500);
  Drive(-400.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  Rotate(-450.0, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(20);
  // Drive(700.0, 100);
  // Lift(-600.0, 100);
  // Claw(300.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceDriveGoal(5));
  // pros::delay(20);
  // Claw(-300.0, 100);
  // pros::delay(500);
  // Lift(500.0, 100);
  // Drive(-200.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceLiftGoal(5));
  // pros::delay(20);
  // Drive(400.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceLiftGoal(5));
  // pros::delay(20);
  // Claw(150.0, 100);
  // pros::delay(500);
  // Lift(200.0, 100);
  // Claw(-150.0, 50);
  // pros::delay(750);
  // Drive(-3000.0, 100);
  // pros::delay(3000);
  // Drive(300.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceLiftGoal(5));
  // pros::delay(20);
  // Rotate(-300.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceLiftGoal(5));
  // pros::delay(20);
  // Drive(1500.0, 100);
  // Lift(-600.0, 100);
  // Claw(150.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceDriveGoal(5));
  // pros::delay(20);
  // Claw(-150.0, 100);
  // pros::delay(500);
  // Lift(500.0, 100);
  // Drive(-200.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceLiftGoal(5));
  // pros::delay(20);
  // Drive(400.0, 100);
  // do {
  //   pros::delay(20);
  // } while (!AtDistanceLiftGoal(5));
  // pros::delay(20);
  // Claw(150.0, 100);
  // pros::delay(500);
  // Lift(200.0, 100);
  // Claw(-150.0, 50);
  // pros::delay(750);
  // Drive(-500.0, 100);
  pros::delay(1000000);
}
