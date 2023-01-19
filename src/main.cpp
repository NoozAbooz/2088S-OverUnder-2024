#include "main.h"

void opcontrol() {
	grafanalib::GUIManager manager;
	manager.setRefreshRate(100);

	grafanalib::VariableGroup<pros::Motor> drivetrainVars({frontLeft, frontRight, backLeft, backRight});
	grafanalib::VariableGroup<pros::Motor> subsystemVars({flywheel, expansion});

	drivetrainVars.add_getter("Temperature", &pros::Motor::get_temperature);
	drivetrainVars.add_getter("Actual Velocity", &pros::Motor::get_actual_velocity);
	drivetrainVars.add_getter("Voltage", &pros::Motor::get_voltage);
	drivetrainVars.add_getter("Efficiency", &pros::Motor::get_efficiency);

	subsystemVars.add_getter("Temperature", &pros::Motor::get_temperature);
	subsystemVars.add_getter("Actual Velocity", &pros::Motor::get_actual_velocity);
	subsystemVars.add_getter("Voltage", &pros::Motor::get_voltage);
	subsystemVars.add_getter("Efficiency", &pros::Motor::get_efficiency);

	manager.registerDataHandler(&drivetrainVars);
	manager.registerDataHandler(&subsystemVars);
	manager.startTask();

	while(true) {
		// Drive code
    	int power = controller.get_analog(ANALOG_LEFT_Y);
    	int turn = controller.get_analog(ANALOG_RIGHT_X);
    	int left = (power - turn) * (12000 / 127);
    	int right = (power + turn) * (12000 / 127);
    	frontLeft.move_voltage(left);
		backLeft.move_voltage(left);
    	frontRight.move_voltage(right);
		backRight.move_voltage(right);

		// Subsystem trigger
     	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		intake.move_voltage(12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		   intake.brake();
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      		intake.move_voltage(-12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		    intake.brake();
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		flywheel.move_voltage(12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			flywheel.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      		flywheel.move_voltage(-12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			flywheel.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      		roller.move_voltage(6000);
		} else {
		    roller.brake();
		}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      		roller.move_voltage(-6000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
			roller.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      		expansion.move_voltage(12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			expansion.brake();
      	}

		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      		expansion.move_voltage(-12000);
		} else if(!controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			expansion.brake();
      	}

		// bind shoot func
		
		controller.print(1, 0, "Speed: %lf | Temp: %dC", motorSpeed, flywheelTemp);
		pros::delay(10);
  	}
}
