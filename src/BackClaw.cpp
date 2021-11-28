#include "main.h"

bool AtDistanceBackClawGoal(int threshold) {
  return (abs((int)(BackClawMotor.get_position()-BackClawMotor.get_target_position())) > threshold);
}

bool AtDistanceBackClawGoalMax(int threshold) {
  return ((int)(BackClawMotor.get_position()) > threshold);
}

bool AtDistanceBackClawGoalMin(int threshold) {
  return ((int)(BackClawMotor.get_position()) < threshold);
}


void BackClaw(double distance, int speed){
    BackClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    BackClawMotor.move_relative(distance, speed);
}


//thread for all claw controls
void BackClaw_fn(void* param) {

  BackClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  int rot_limit_max, rot_limit_min, starting_rot;
  starting_rot = BackClawMotor.get_position();
  rot_limit_min = 0;
  rot_limit_max = 370;

  while (true) {

    if (master.get_digital(DIGITAL_X)){
      BackClawMotor.move_voltage(5000);
      do {
        pros::delay(20);
      } while (BackClawMotor.get_position() < rot_limit_max);
      pros::delay(20);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_B) && BackClawMotor.get_position() > rot_limit_min) {
      BackClawMotor.move_voltage(-5000);
      do {
        pros::delay(20);
      } while (BackClawMotor.get_position() > rot_limit_min);
      pros::delay(20);
      //pros::delay(20);
    }
    else {
      if (25 < abs((int)(BackClawMotor.get_position() - rot_limit_max)) && abs((int)(BackClawMotor.get_position() - rot_limit_max)) < 30 && BackClawMotor.get_position() < rot_limit_max){
        BackClawMotor.move_voltage(5000);
        do {
          pros::delay(20);
        } while (BackClawMotor.get_position() < rot_limit_max);
        pros::delay(20);
      }
      else{
          BackClawMotor.move_voltage(0);
      }
      //pros::delay(20);
    }

  }

}
