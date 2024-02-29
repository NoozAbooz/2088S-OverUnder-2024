#include "main.h"

#include <iostream>

double global_kp = 0;
double global_ki = 0;
double global_kd = 0;
double global_timeOut = 0;

using namespace strait;

//strait::LateralPID pid;

strait::LateralPID::LateralPID() {
	pid.kp = global_kp;
	pid.ki = global_ki;
	pid.kd = global_kd;
	pid.timeOut = global_timeOut;
}

void strait::LateralPID::set_lateral_constants(double kp, double ki, double kd, double timeOut) {
	pid.kp = kp;
	pid.ki = ki;
	pid.kd = kd;	
	pid.timeOut = timeOut;
}

double strait::LateralPID::compute_lateral_pid(double target, double maxSpeed, double minSpeed) {
	double prevError = 0;
	double integral = 0;
	double derivative = 0;
	double power = 0;
	double currentTime = 0;

	double tolerance = 0;
	double local_timer = 0;

	while (true) {
		double error = target - leftDrive.get_positions().at(0);
		integral = (integral + error);
		derivative = (error - prevError);

		power = (pid.kp * error) + (pid.ki * integral) + (pid.kd * derivative);

		if (power * (12000.0 / 127) > maxSpeed * (12000.0 / 127)) {
			power = maxSpeed;
		} else if (power * (12000.0 / 127) < -maxSpeed * (12000.0 / 127)) {
			power = -maxSpeed;
		}

		if (power * (12000.0 / 127) < minSpeed * (12000.0 / 127)) {
			power = minSpeed;
		} else if (power * (12000.0 / 127) > -minSpeed * (12000.0 / 127)) {
			power = -minSpeed;
		}

		return power * (12000.0 / 127);

		if (local_timer > (pid.timeOut * 100)) {
			return;
		}

		local_timer++;
		prevError = error;
		pros::delay(10);
	}
}
