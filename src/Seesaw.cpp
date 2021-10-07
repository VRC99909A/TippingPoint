#include "main.h"

bool AtDistanceClawGoal(int threshold) {
  return (abs((int)(ClawMotor.get_position()-ClawMotor.get_target_position())) < threshold);
}


void Claw(double distance, int speed){
    ClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    ClawMotor.move_relative(distance, speed);
}


//thread for all claw controls
void Claw_fn(void* param) {

  ClawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {

    if (master.get_digital(DIGITAL_R1)) {
      ClawMotor.move_voltage(7000);
      //pros::delay(20);
    }
    else if (master.get_digital(DIGITAL_R2)) {
      ClawMotor.move_voltage(-5000);
      //pros::delay(20);
    }
    else {
      ClawMotor.move_voltage(0);
      //pros::delay(20);
    }

  }

}
