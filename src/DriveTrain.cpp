#include "main.h"

//Returns true/false as to whether the drive wheels have reached their position goal set by driveForDistance
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

//turn to target position, but does not wait for them to reach their target
void Rotate(double distance, int speed) {
  FLMotor.move_relative(distance, speed);
  BLMotor.move_relative(distance, speed);
  FRMotor.move_relative(-distance, speed);
  BRMotor.move_relative(-distance, speed);
}

void RotateDegreesLeft(double degrees) {
  do{
    FLMotor.move_velocity(100.0);
    BLMotor.move_velocity(100.0);
    FRMotor.move_velocity(-100.0);
    BRMotor.move_velocity(-100.0);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() > 360.0-degrees+20.0 || ImuSensor.get_heading() < 10.0); //turn left until desired degree from default heading (0)
  //correction track
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);

  do{
    if (ImuSensor.get_heading() > 360.0-degrees){//correct left
      FLMotor.move_velocity(25);
      BLMotor.move_velocity(25);
      FRMotor.move_velocity(-25);
      BRMotor.move_velocity(-25);
    }
    else if (ImuSensor.get_heading() < 360.0-degrees){//correct right
      FLMotor.move_velocity(-25);
      BLMotor.move_velocity(-25);
      FRMotor.move_velocity(25);
      BRMotor.move_velocity(25);
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading()-360.0+degrees > 0.1 || ImuSensor.get_heading()-360.0+degrees < -0.1);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
}

void RotateDegreesRight(double degrees) {
  do{
    FLMotor.move_velocity(-100);
    BLMotor.move_velocity(-100);
    FRMotor.move_velocity(100);
    BRMotor.move_velocity(100);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() < degrees-20.0 || ImuSensor.get_heading() > 350.0); //turn right until desired degree from default heading (0)
  //correction track
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);

  do{
    if (ImuSensor.get_heading() < degrees){//correct right
      FLMotor.move_velocity(-25);
      BLMotor.move_velocity(-25);
      FRMotor.move_velocity(25);
      BRMotor.move_velocity(25);
    }
    else if (ImuSensor.get_heading() > degrees){//correct left
      FLMotor.move_velocity(25);
      BLMotor.move_velocity(25);
      FRMotor.move_velocity(-25);
      BRMotor.move_velocity(-25);
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading()-degrees > 0.1 || ImuSensor.get_heading()-degrees < -0.1);
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
}


void TurnRightToZero() {
  do{
    FLMotor.move_velocity(-100);
    BLMotor.move_velocity(-100);
    FRMotor.move_velocity(100);
    BRMotor.move_velocity(100);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() < 360.0-20.0); //turn right until 360 degree roughly
  //correction track
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
  void CorrectToZero();
}


void TurnLeftToZero() {
  do{
    FLMotor.move_velocity(100);
    BLMotor.move_velocity(100);
    FRMotor.move_velocity(-100);
    BRMotor.move_velocity(-100);
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() > 20.0); //turn left until 0 degree roughly
  //correction track
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
  void CorrectToZero();
}


void CorrectToZero() {
  do{
    if (ImuSensor.get_heading() < 360.0 && ImuSensor.get_heading() > 270.0){//correct right
      FLMotor.move_velocity(-25);
      BLMotor.move_velocity(-25);
      FRMotor.move_velocity(25);
      BRMotor.move_velocity(25);
    }
    else if (ImuSensor.get_heading() > 0.0 && ImuSensor.get_heading() < 90.0){ //correct left
      FLMotor.move_velocity(25);
      BLMotor.move_velocity(25);
      FRMotor.move_velocity(-25);
      BRMotor.move_velocity(-25);
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (((360.0 - ImuSensor.get_heading()) > 0.1 && ImuSensor.get_heading() > 270.0) || ((ImuSensor.get_heading()) > 0.1 && ImuSensor.get_heading() < 90.0));
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);
}


void TurnLeftPIDfromZero(double degrees){
  do{
    if ((ImuSensor.get_heading() <= 360.0) && (ImuSensor.get_heading() >= 90.0)){//correct right
      FLMotor.move_velocity(100 - (int)(((1-(ImuSensor.get_heading()-360+degrees)/degrees))*90.0));
      BLMotor.move_velocity(100 - (int)(((1-(ImuSensor.get_heading()-360+degrees)/degrees))*90.0));
      FRMotor.move_velocity(-(100 - (int)(((1-(ImuSensor.get_heading()-360+degrees)/degrees))*90.0)));
      BRMotor.move_velocity(-(100 - (int)(((1-(ImuSensor.get_heading()-360+degrees)/degrees))*90.0)));
    }
    else if ((ImuSensor.get_heading() >= 0.0) && (ImuSensor.get_heading() < 90.0)){ //correct left at full speed
      FLMotor.move_velocity(100);
      BLMotor.move_velocity(100);
      FRMotor.move_velocity(-100);
      BRMotor.move_velocity(-100);
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while ((ImuSensor.get_heading() > (360.0-degrees)) || (ImuSensor.get_heading() < 45.0)); //turn left until desired degree from default heading (0)
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
}

void TurnRightPIDfromZero(double degrees){
  do{
    if (ImuSensor.get_heading() <= 360.0 && ImuSensor.get_heading() > 270.0){//correct right
      FLMotor.move_velocity(-100);
      BLMotor.move_velocity(-100);
      FRMotor.move_velocity(100);
      BRMotor.move_velocity(100);
    }
    else if (ImuSensor.get_heading() >= 0.0 && ImuSensor.get_heading() <= 270.0){ //correct left at full speed
      FLMotor.move_velocity(-(100 - (int)(((1-(degrees - ImuSensor.get_heading())/degrees))*90.0)));
      BLMotor.move_velocity(-(100 - (int)(((1-(degrees - ImuSensor.get_heading())/degrees))*90.0)));
      FRMotor.move_velocity(100 - (int)(((1-(degrees - ImuSensor.get_heading())/degrees))*90.0));
      BRMotor.move_velocity(100 - (int)(((1-(degrees - ImuSensor.get_heading())/degrees))*90.0));
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() > 315.0 || ImuSensor.get_heading() < degrees); //turn left until desired degree from default heading (0)
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
}

void TurnLeft(double degrees, int speed){
  do{
    if ((ImuSensor.get_heading() <= 360.0) && (ImuSensor.get_heading() >= 90.0)){//correct right
      FLMotor.move_velocity(speed);
      BLMotor.move_velocity(speed);
      FRMotor.move_velocity(-speed);
      BRMotor.move_velocity(-speed);
    }
    else if ((ImuSensor.get_heading() >= 0.0) && (ImuSensor.get_heading() < 90.0)){ //correct left at full speed
      FLMotor.move_velocity(speed);
      BLMotor.move_velocity(speed);
      FRMotor.move_velocity(-speed);
      BRMotor.move_velocity(-speed);
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while ((ImuSensor.get_heading() > (360.0-degrees)) || (ImuSensor.get_heading() < 45.0)); //turn left until desired degree from default heading (0)
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
}

void TurnRight(double degrees, int speed){
  do{
    if (ImuSensor.get_heading() <= 360.0 && ImuSensor.get_heading() > 270.0){//correct right
      FLMotor.move_velocity(-speed);
      BLMotor.move_velocity(-speed);
      FRMotor.move_velocity(speed);
      BRMotor.move_velocity(speed);
    }
    else if (ImuSensor.get_heading() >= 0.0 && ImuSensor.get_heading() <= 270.0){ //correct left at full speed
      FLMotor.move_velocity(-speed);
      BLMotor.move_velocity(-speed);
      FRMotor.move_velocity(speed);
      BRMotor.move_velocity(speed);
    }
    //printf("IMU get heading: %f degrees\n", ImuSensor.get_heading());
  } while (ImuSensor.get_heading() > 315.0 || ImuSensor.get_heading() < degrees); //turn left until desired degree from default heading (0)
  FLMotor.move_velocity(0);
  BLMotor.move_velocity(0);
  FRMotor.move_velocity(0);
  BRMotor.move_velocity(0);

  pros::delay(250);
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
