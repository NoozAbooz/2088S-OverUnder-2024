#include "deviceGlobals.hpp"
#include "main.h"

double global_kp = 0;
double global_kd = 0;
double global_timeOut = 0;

using namespace strait;

//strait::LateralPID pid;

strait::LateralPID::LateralPID() {
	pid.kp = global_kp;
	pid.kd = global_kd;
	pid.timeOut = global_timeOut;
}

void strait::LateralPID::set_constants(double kp, double kd, double timeOut) {
	pid.kp = kp;
	pid.kd = kd;	
	pid.timeOut = timeOut;
}

void strait::LateralPID::set_lateral_pid(double target, double maxSpeed) {
	double prevError = 0;
	double derivative = 0;
	double power = 0;
	double currentTime = 0;

	double tolerance = 0;
	double local_timer = 0;

	while (true) {
		double error = target - leftDrive.get_positions().at(0);
		derivative = (error - prevError);
		power = (pid.kp * error) + (pid.kd * derivative);

		if (power * (12000.0 / 127) > maxSpeed * (12000.0 / 127)) {
			power = maxSpeed;
		} else if (power * (12000.0 / 127) < -maxSpeed * (12000.0 / 127)) {
			power = -maxSpeed;
		}

		leftDrive.move_voltage(power * (12000.0 / 127));
		rightDrive.move_voltage(power * (12000.0 / 127));

		if (local_timer > (pid.timeOut * 100)) {
			leftDrive.move_voltage(0);
			rightDrive.move_voltage(0);
			return;
		}

		local_timer++;
		pros::delay(10);
	}
}
