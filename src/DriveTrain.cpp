#include "main.h"

// Returns true/false as to whether the drive wheels have reached their position goal set by driveForDistance
bool AtDistanceDriveGoal(int threshold) {
  return (abs((int)(FLMotor.get_position()-FLMotor.get_target_position())) < threshold);
}

//set drive target, but does not wait for them to reach their target
void Drive(double distance, int speed) {
  FLMotor.move_relative(distance, speed);
  BLMotor.move_relative(distance, speed);
  FRMotor.move_relative(distance, speed);
  BRMotor.move_relative(distance, speed);
}

void DriveVel(int power){
  FLMotor.move_velocity(power);
  BLMotor.move_velocity(power);
  FRMotor.move_velocity(power);
  BRMotor.move_velocity(power);
}

//turn to target position, but does not wait for them to reach their target
void Rotate(double distance, int speed) {
  FLMotor.move_relative(distance, speed);
  BLMotor.move_relative(distance, speed);
  FRMotor.move_relative(-distance, speed);
  BRMotor.move_relative(-distance, speed);
}

//turn left to target heading - top speed 200
void TurnLeftToHeading(double target) {
  double delta; //declare delta
  if ( ImuSensor.get_heading() - target < 0.0 ) { //crossing zero
    delta = 360.0 + ImuSensor.get_heading() - target;
  }
  else { //not crossing zero
    delta = ImuSensor.get_heading() - target;
  }

  do{
    FLMotor.move_velocity(50);
    BLMotor.move_velocity(50);
    FRMotor.move_velocity(-50);
    BRMotor.move_velocity(-50);
    pros::delay(50);
    if ( ImuSensor.get_heading() - target < 0.0 ) { //crossing zero
      delta = 360.0 + ImuSensor.get_heading() - target;
    }
    else { //not crossing zero
      delta = ImuSensor.get_heading() - target;
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (delta > 0.5);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
}

//turn left to target heading  - top speed 200
void TurnRightToHeading(double target) {
  double delta; //declare delta
  if (target - ImuSensor.get_heading() < 0.0 ) { //crossing zero
    delta = 360.0 + target - ImuSensor.get_heading();
  }
  else { //not crossing zero
    delta = target - ImuSensor.get_heading();
  }

  do{
    FLMotor.move_velocity(-50);
    BLMotor.move_velocity(-50);
    FRMotor.move_velocity(50);
    BRMotor.move_velocity(50);
    pros::delay(50);
    if ( target - ImuSensor.get_heading() < 0.0 ) { //crossing zero
      delta = 360.0 + target - ImuSensor.get_heading();
    }
    else { //not crossing zero
      delta = target - ImuSensor.get_heading();
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (delta > 0.5);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
}

//speed turn left back to north 0/360  - top speed 200
void TurnLeftToZero() {
  do{
    FLMotor.move_velocity(100);
    BLMotor.move_velocity(100);
    FRMotor.move_velocity(-100);
    BRMotor.move_velocity(-100);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() > 20.0); //turn left at full speed until 20 degree roughly
  //correction track
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
  void CorrectToZero();
}

//speed turn right back to north 0/360  - top speed 200
void TurnRightToZero() {
  do{
    FLMotor.move_velocity(-100);
    BLMotor.move_velocity(-100);
    FRMotor.move_velocity(100);
    BRMotor.move_velocity(100);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() < 360.0-20.0); //turn right at full speed until 340 degree roughly
  //correction track
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
  void CorrectToZero();
}

//slow turn back to north 0/360 from either direction left/right
void CorrectToZero() {
  do{
    if (ImuSensor.get_heading() < 360.0 && ImuSensor.get_heading() > 270.0){//correct right
      FLMotor.move_velocity(-35);
      BLMotor.move_velocity(-35);
      FRMotor.move_velocity(35);
      BRMotor.move_velocity(35);
    }
    else if (ImuSensor.get_heading() > 0.0 && ImuSensor.get_heading() < 90.0){ //correct left
      FLMotor.move_velocity(35);
      BLMotor.move_velocity(35);
      FRMotor.move_velocity(-35);
      BRMotor.move_velocity(-35);
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while ((((360.0 - ImuSensor.get_heading()) > 5) && (ImuSensor.get_heading() > 270.0)) || (((ImuSensor.get_heading()) > 5) && (ImuSensor.get_heading() < 90.0)));
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
}


//thread for all drive train controls
void DriveTrain_fn(void* param) {
  /** - tank drive variables -
  int LeftControl = master.get_analog(ANALOG_LEFT_Y);
  int RightControl = master.get_analog(ANALOG_RIGHT_Y);
  **/

  /** - arcade drive variables -**/
  //int power = master.get_analog(ANALOG_LEFT_Y); //left joystick Y drive straight
  int power = master.get_analog(ANALOG_RIGHT_Y); //right joystick Y drive straight
  int turn = master.get_analog(ANALOG_RIGHT_X);
  int LeftControl = power - turn;
  int RightControl = power + turn;

  while (true){

    /** - tank drive -
    //get joysticks position value and maps them to a variable
    LeftControl = master.get_analog(ANALOG_LEFT_Y);
    RightControl = master.get_analog(ANALOG_RIGHT_Y);

    FLMotor.move(LeftControl);
    BLMotor.move(LeftControl);
    FRMotor.move(RightControl);
    BRMotor.move(RightControl);
    pros::delay(2);
    **/

    /* arcade drive*/
    //power = master.get_analog(ANALOG_LEFT_Y); //left joystick Y drive straight
    power = master.get_analog(ANALOG_RIGHT_Y); //right joystick Y drive straight
    turn = master.get_analog(ANALOG_RIGHT_X);
    LeftControl = power - turn;
    RightControl = power + turn;
    FLMotor.move(LeftControl);
    BLMotor.move(LeftControl);
    FRMotor.move(RightControl);
    BRMotor.move(RightControl);
    pros::delay(2);

  }
}
