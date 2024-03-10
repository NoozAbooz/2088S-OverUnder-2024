#include "main.h"

using namespace strait;

void strait::moveRaw(int voltage, int time) {
	leftDrive.move_voltage(voltage);
	rightDrive.move_voltage(voltage);

	pros::delay(time);

	leftDrive.move_voltage(0);
	rightDrive.move_voltage(0);
}

void strait::calibrateIMU() {
    int attempt = 1;
    bool calibrated = false;
    // calibrate inertial, and if calibration fails, then repeat 5 times or until successful
    while (attempt <= 5 && !isDriverControl()) {
        inertial.reset();
        // wait until IMU is calibrated
        do pros::delay(10);
        while (inertial.get_status() != 0xFF && inertial.is_calibrating() && !isDriverControl());
        // exit if imu has been calibrated
        if (!isnanf(inertial.get_heading()) && !isinf(inertial.get_heading())) {
            calibrated = true;
            break;
        }
        // indicate error
        pros::c::controller_rumble(pros::E_CONTROLLER_MASTER, "---");
        printf("IMU calibration failed, attempt %d\n", attempt);
        attempt++;
    }
    // check if its driver control through the comp switch
    if (isDriverControl() && !calibrated) {
        printf("IMU calibration failed, driver mode is now on\n");
    }
    // check if calibration attempts were successful
    if (attempt > 5) {
        printf("IMU calibration failed, no successful attempts\n");
    }
}
