#include "main.h"

//Start of SkillsAutonOne
void SkillsAutonOne(){
  ImuSensor.set_heading(0.0); //reset inertial sensor heading
  //ImuSensor.reset();

  Drive(300.0, 50); //drive forward
  Claw(300.0, 100); //raise seesaw to release front claw
  pros::delay(500); //wait for front claw to deploy before open up snap

  Claw(-375.0, 100); //lower seesaw to get ready to capture low neutal goal on the right

  Snap(-250.0, 50); //open up snap
  Drive(1400.0, 100);//drive forward to capture low neutal goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  FLMotor.move_velocity(30); //drive forward slowly to capture low neutal goal on the left
  BLMotor.move_velocity(30);
  FRMotor.move_velocity(30);
  BRMotor.move_velocity(30);
  Snap(400.0, 100);//close snap to capture low neutal goal on the right
  pros::delay(500);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  Drive(-250, 100);//pull back a little
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

/**

  Rotate(150.0, 100); //turn left 35 degree to capture the alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

**/

  //RotateDegreesLeft(45.0);
  TurnLeft(40.0, 30);
  pros::lcd::set_text(1, std::to_string(ImuSensor.get_heading()));

/**
  ImuSensor.set_heading(0.0); //reset gyro sensor
  do{
    FLMotor.move_velocity(100);
    BLMotor.move_velocity(100);
    FRMotor.move_velocity(-100);
    BRMotor.move_velocity(-100);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() > 335.0 || ImuSensor.get_heading() < 15.0); //turn left until 45 degree
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
**/

  Drive(-600, 80);//drive backwards to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  BackClaw(370.0, 100); //lift BackClaw to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500); //allow time for the backclaw to lift up

  Drive(1500, 80);//drive forward towards the platform
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Claw(650.0, 100);//raise seesaw to get ready to deposite low neutal goal
  Drive(1000, 80);//drive forward to push rings out of the way
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  pros::delay(5000);
  Drive(-300, 80);//pull back
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //turn right 45 degree back to starting heading)
  CorrectToZero();
  pros::lcd::set_text(1, std::to_string(ImuSensor.get_heading()));
  pros::delay(10000);
/**
  //ImuSensor.set_heading(0.0); //reset gyro sensor
  do{
    FLMotor.move_velocity(-100);
    BLMotor.move_velocity(-100);
    FRMotor.move_velocity(100);
    BRMotor.move_velocity(100);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() > 350.0 || ImuSensor.get_heading() < 30.0); //turn left until 45 degree
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
  **/
  Drive(400, 100);//drive forward to level the platform
  pros::delay(1000);
  Drive(-400, 100);//pull back
  Claw(-150.0, 100);//lower seesaw
  pros::delay(1000);
  void CorrectToZero();

  Snap(-250.0, 100); //open up snap
  Drive(400, 100);//thrust forward towards the platform
  pros::delay(1000);
  void CorrectToZero();

  //Claw(-200.0, 100); //lower seesaw to deposit goal
  Drive(-700, 80);//pull back
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Rotate(100.0, 100); //turn left 35 degree to get ready to push tall neutal goal
  //do {
  //  pros::delay(20);
  //} while (!AtDistanceDriveGoal(5));

  Drive(-800, 80);//drive backward to push tall neutal goal to alliance zone
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(600, 80);//drive back up towards the platform
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Rotate(-100.0, 100); //turn right back to face platform
  //do {
  //  pros::delay(20);
  //} while (!AtDistanceDriveGoal(5));

  BackClaw(-200.0, 100); //lower backclaw
  pros::delay(1000);

  Claw(-400.0, 100); //lower seesaw
  BackClaw(-170.0, 100); //lower backclaw
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500);

  Drive(400, 80);//drive forward to allow clearance between alliance goal
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  BackClaw(370.0, 100); //raise backclaw
  pros::delay(1000);

  //RotateDegreesRight(180.0);
  TurnLeftPIDfromZero(170.0);

  Claw(-300.0, 100); //lower seesaw

  Drive(600, 80);//drive towards the alliance goal
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  FLMotor.move_velocity(30); //drive forward slowly to capture the alliance goal
  BLMotor.move_velocity(30);
  FRMotor.move_velocity(30);
  BRMotor.move_velocity(30);
  Snap(400.0, 100);//close snap to capture the alliance goal
  pros::delay(500);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  Claw(500.0, 100); //raise seesaw

  //turn right 180 degree (back to starting heading)
  TurnRightToZero();

  Snap(-250.0, 100); //open up snap
  pros::delay(1000);
  Drive(1300, 100);//drive forward to platform
  pros::delay(4000);
  //Claw(-100.0, 100); //lower seesaw

  Drive(-300, 100);//pull back
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

/**
    do{
      FLMotor.move_velocity(100);
      BLMotor.move_velocity(100);
      FRMotor.move_velocity(-100);
      BRMotor.move_velocity(-100);
      //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
    } while (ImuSensor.get_heading() > 1.5); //turn left to face the wall
    FLMotor.move_velocity(0);
    BLMotor.move_velocity(0);
    FRMotor.move_velocity(0);
    BRMotor.move_velocity(0);


    do{
      FLMotor.move_velocity(100);
      BLMotor.move_velocity(100);
      FRMotor.move_velocity(100);
      BRMotor.move_velocity(100);
      //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
    } while (DistanceSensor.get() > 800); //turn left to face the wall
    FLMotor.move_velocity(0);
    BLMotor.move_velocity(0);
    FRMotor.move_velocity(0);
    BRMotor.move_velocity(0);
    **/
    //RotateDegreesLeft(90.0);
    TurnLeftPIDfromZero(90.0);

    Drive(1000, 100);//drive forward
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    RotateDegreesLeft(180.0);

/**
    Rotate(250.0, 100); //turn left to face the neutal goal
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    BackClaw(-370.0, 100); //lower backclaw
    Claw(-500.0, 100); //lower seesaw

    Drive(600, 100);//drive forward
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    FLMotor.move_velocity(30); //drive forward slowly to capture low neutal goal on the left
    BLMotor.move_velocity(30);
    FRMotor.move_velocity(30);
    BRMotor.move_velocity(30);
    Snap(400.0, 100);//close snap to capture low neutal goal on the right
    pros::delay(500);
    FLMotor.move_velocity(0);
    BLMotor.move_velocity(0);
    FRMotor.move_velocity(0);
    BRMotor.move_velocity(0);
    **/
}


//Start of SkillsAutonTwo
//start on the right side
void SkillsAutonTwo(){

  Drive(300.0, 50); //drive forward
  Claw(300.0, 100); //raise seesaw to release front claw
  pros::delay(500); //wait for front claw to deploy before open up snap

  Claw(-375.0, 100); //lower seesaw to get ready to capture low neutal goal on the right

  Snap(-250.0, 50); //open up snap
  Drive(1400.0, 100);//drive forward to capture low neutal goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  FLMotor.move_velocity(30); //drive forward slowly to capture low neutal goal on the left
  BLMotor.move_velocity(30);
  FRMotor.move_velocity(30);
  BRMotor.move_velocity(30);
  Snap(400.0, 100);//close snap to capture low neutal goal on the right
  pros::delay(500);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  Drive(-300, 100);//pull back a little
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(150.0, 100); //turn left 35 degree to capture the alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));


  Drive(-600, 80);//drive backwards to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  BackClaw(370.0, 100); //lift BackClaw to capture alliance goal on the right
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500); //allow time for the backclaw to lift up

  Drive(1500, 80);//drive forward towards the platform
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Claw(650.0, 100);//raise seesaw to get ready to deposite low neutal goal
  Drive(1100, 80);//drive forward to push rings out of the way
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-300, 80);//pull back
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(-150.0, 100); //turn right 35 degree to face platform
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(400, 100);//drive forward to level the platform
  pros::delay(1000);
  Drive(-400, 100);//pull back
  Claw(-100.0, 100);//lower seesaw

  Snap(-250.0, 100); //open up snap
  Drive(400, 100);//thrust forward towards the platform
  pros::delay(1000);
// first goal deposited


  Drive(-700, 80);//pull back
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-800, 80);//drive backward to push tall neutal goal to alliance zone
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(600, 80);//drive back up towards the platform
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  BackClaw(-200.0, 100); //lower backclaw
  pros::delay(1000);

  Claw(-400.0, 100); //lower seesaw
  BackClaw(-170.0, 100); //lower backclaw
  do {
    pros::delay(20);
  } while (!AtDistanceBackClawGoal(10));
  pros::delay(500);

  Drive(400, 80);//drive forward to allow clearance between alliance goal
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  BackClaw(370.0, 100); //raise backclaw
  pros::delay(1000);

  Rotate(-620.0, 100); //make 180 degree turn on the right
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Claw(-300.0, 100); //lower seesaw

  Drive(600, 80);//drive towards the alliance goal
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  FLMotor.move_velocity(30); //drive forward slowly to capture low neutal goal on the left
  BLMotor.move_velocity(30);
  FRMotor.move_velocity(30);
  BRMotor.move_velocity(30);
  Snap(400.0, 100);//close snap to capture low neutal goal on the right
  pros::delay(500);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  Claw(500.0, 100); //raise seesaw
  Rotate(620.0, 100); //turn 180 to face platform on the left
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Snap(-250.0, 100); //open up snap
  pros::delay(1000);
  Drive(1300, 100);//drive forward to platform
  pros::delay(3000);
  //Claw(-100.0, 100); //lower seesaw

  Drive(-300, 100);//pull back
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));


// first stage complete

    Rotate(350.0, 100); //turn left 90 degree to capture the alliance goal on the right
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    BackClaw(-370.0, 100); //lower backclaw

/**
    Drive(1300, 100);//drive forward
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));
    Drive(-300, 100);//drive forward
    Claw(-500.0, 100); //lower seesaw
    pros::delay(1000);


    RotateDegreesLeft(185.0);

    Drive(300.0, 50); //drive forward
    pros::delay(1000);


    FLMotor.move_velocity(30); //drive forward slowly to capture low neutal goal on the left
    BLMotor.move_velocity(30);
    FRMotor.move_velocity(30);
    BRMotor.move_velocity(30);
    Snap(400.0, 100);//close snap to capture low neutal goal on the right
    pros::delay(500);
    FLMotor.move_velocity(0);
    BLMotor.move_velocity(0);
    FRMotor.move_velocity(0);
    BRMotor.move_velocity(0);

    Drive(-300, 100);//pull back a little
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    Rotate(150.0, 100); //turn left 35 degree to capture the alliance goal on the right
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    Drive(-600, 80);//drive backwards to capture alliance goal on the right
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    BackClaw(370.0, 100); //lift BackClaw to capture alliance goal on the right
    do {
      pros::delay(20);
    } while (!AtDistanceBackClawGoal(10));
    pros::delay(500); //allow time for the backclaw to lift up

    Drive(1500, 80);//drive forward towards the platform
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    Claw(650.0, 100);//raise seesaw to get ready to deposite low neutal goal
    Drive(1100, 80);//drive forward to push rings out of the way
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    Drive(-300, 80);//pull back
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    Rotate(-150.0, 100); //turn right 35 degree to face platform
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));




    Drive(400, 100);//drive forward to level the platform
    pros::delay(1000);
    Drive(-400, 100);//pull back
    Claw(-100.0, 100);//lower seesaw

    Snap(-250.0, 100); //open up snap
    Drive(400, 100);//thrust forward towards the platform
    pros::delay(1000);

    //Claw(-200.0, 100); //lower seesaw to deposit goal
    Drive(-700, 80);//pull back
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));



    BackClaw(-200.0, 100); //lower backclaw
    pros::delay(1000);

    Claw(-400.0, 100); //lower seesaw
    BackClaw(-170.0, 100); //lower backclaw
    do {
      pros::delay(20);
    } while (!AtDistanceBackClawGoal(10));
    pros::delay(500);

    Drive(400, 80);//drive forward to allow clearance between alliance goal
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    BackClaw(370.0, 100); //raise backclaw
    pros::delay(1000);

    Rotate(-620.0, 100); //make 180 degree turn on the right
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    Claw(-300.0, 100); //lower seesaw

    Drive(600, 80);//drive towards the alliance goal
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    FLMotor.move_velocity(30); //drive forward slowly to capture the alliance goal
    BLMotor.move_velocity(30);
    FRMotor.move_velocity(30);
    BRMotor.move_velocity(30);
    Snap(400.0, 100);//close snap to capture the alliance goal
    pros::delay(500);
    FLMotor.move_velocity(0);
    BLMotor.move_velocity(0);
    FRMotor.move_velocity(0);
    BRMotor.move_velocity(0);

    Claw(500.0, 100); //raise seesaw
    Rotate(620.0, 100); //turn 180 to face platform on the left
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));

    Snap(-250.0, 100); //open up snap
    pros::delay(1000);
    Drive(1300, 100);//drive forward to platform
    pros::delay(3000);
    //Claw(-100.0, 100); //lower seesaw

    Drive(-300, 100);//pull back
    do {
      pros::delay(20);
    } while (!AtDistanceDriveGoal(5));


**/
}
