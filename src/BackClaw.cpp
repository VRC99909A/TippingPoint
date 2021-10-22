#include "main.h"

bool AtDistanceBackClawGoal(int threshold) {
  return (abs((int)(BackClawMotor.get_position()-BackClawMotor.get_target_position())) < threshold);
}


void BackClaw(double distance, int speed){
    BackClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    BackClawMotor.move_relative(distance, speed);
}


//thread for all claw controls
void BackClaw_fn(void* param) {

  BackClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {

    if (master.get_digital(DIGITAL_UP)) {
      BackClawMotor.move_voltage(5000); //max voltage 12000
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_DOWN)) {
      BackClawMotor.move_voltage(-5000);
      //pros::delay(20);
    }
    else {
      BackClawMotor.move_voltage(0);
      //pros::delay(20);
    }

  }

}
