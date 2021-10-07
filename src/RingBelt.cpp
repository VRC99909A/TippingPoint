#include "main.h"

bool AtDistanceLiftGoal(int threshold) {
  return (abs((int)(LiftMotor.get_position()-LiftMotor.get_target_position())) < threshold);
}


void Lift(double distance, int speed){
    LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    LiftMotor.move_relative(distance, speed);
}


//thread for all lift controls
void Lift_fn(void* param) {

  LiftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

  while (true) {

    if (master.get_digital(DIGITAL_L1)) {
      LiftMotor.move_voltage(7000);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_L2)) {
      LiftMotor.move_voltage(-7000);
      //pros::delay(20);
    }
    else {
      LiftMotor.move_voltage(0);
      //pros::delay(20);
    }

  }
}
