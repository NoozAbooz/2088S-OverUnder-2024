#include "main.h"

void opcontrol() {
  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);

  while (true) {
    chassis.tank(); // Tank control
    chassis.arcade_standard(ez::SPLIT); // Standard split arcade

    // Intake
     	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		intake.move_voltage(12000);
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
	  		intake.move_voltage(-12000);
		} else {
		    intake.brake();
		}
		
		// Catapult
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		catapult.move_voltage(12000);
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			catapult.move_voltage(-12000);
		} else {
			catapult.brake();
      	}

		// Roller
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      		roller.move_voltage(5000);
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
			roller.move_voltage(-5000);
		} else {
		    roller.brake();
		}

		// Expansion
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      		expansion.move_voltage(7000);
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			expansion.move_voltage(-4000);
		} else {
			expansion.brake();
    }
		
		master.print(1, 0, "%.0f RPM %.0f°C %.0f°C     ", (100 * round((flywheel.get_actual_velocity() * 5)/100)), flywheel.get_temperature(), frontLeft.get_temperature());

    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.

  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
}
