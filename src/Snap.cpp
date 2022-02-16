#include "main.h"

bool AtDistanceSnapGoal(int threshold) {
  return (abs((int)(SnapMotor.get_position()-SnapMotor.get_target_position())) > threshold);
}

bool AtDistanceSnapGoalMax(int threshold) {
  return ((int)(SnapMotor.get_position()) > threshold);
}

bool AtDistanceSnapGoalMin(int threshold) {
  return ((int)(SnapMotor.get_position()) < threshold);
}


void Snap(double distance, int speed){
    SnapMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    SnapMotor.move_relative(distance, speed);
}


// thread for all claw controls
void Snap_fn(void* param) {

  SnapMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {

    if (master.get_digital(DIGITAL_DOWN)) {
      SnapMotor.move_voltage(8000); //1000; max voltage 12000
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_UP) && (int)SnapMotor.get_position() < 300) {
      SnapMotor.move_voltage(-8000); //-10000
      //pros::delay(20);
    }
    else {
      //SnapMotor.move_voltage(0);
      SnapMotor.move_velocity(0);
      //pros::delay(20);
    }

  }


}
