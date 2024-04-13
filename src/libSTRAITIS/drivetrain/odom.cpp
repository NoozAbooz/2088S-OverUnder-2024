#include "main.h"

using namespace strait;

double    x = 0; // global X
double    y = 0; // global Y
double    theta; // global theta

Position odom_pos;

// Gyro scale effect from 2775V
// If it is a bit less than 360, that's your number. If it is a bit more than 0, add 360 and that's your number.
double gyro_scale1 = 357.91;
double gyro_scale2 = 360.2;

double wheel_diameter = 3.25;
double gear_ratio = (36.0 / 48.0); //maybe change to rpm
double track_width = 12.5;
double wheel_circumference = M_PI * wheel_diameter;

double get_imu_rotation() {
	double rotation1 = inertial.get_rotation();
	double rotation2 = inertial2.get_rotation();

	double average_rotation = ((rotation1 * (360.0 / gyro_scale1)) + (rotation2 * (360.0 / gyro_scale2))) / 2;
	return average_rotation;
}

double get_dt_distance_travelled() { 
	double avg_position = (leftDrive.at(1).get_position() + rightDrive.at(1).get_position()) / 2;
	return (avg_position / 360) * wheel_circumference * gear_ratio;
}

double get_dt_heading() {
	double left_distance = (leftDrive.at(1).get_position() / 360) * wheel_circumference * gear_ratio;
	double right_distance = (rightDrive.at(1).get_position() / 360) * wheel_circumference * gear_ratio;

	double heading_in_radians = (right_distance - left_distance) / track_width;
	return to_deg(heading_in_radians);
}

void strait::odomThread() {
	double avg_heading;
	double previous_distance_travelled;
	double delta_distance;
	double heading;
	double distance_travelled;

	while (true) {
		// Find average between dt and imu heading
		// wrap to [0, 360)
		avg_heading = fmod((get_dt_heading() + get_imu_rotation()) / 2, 360);
		heading = fmod((360 - get_imu_rotation()) + 90, 360);
		theta = fmod(get_imu_rotation(), 360);

		distance_travelled = get_dt_distance_travelled();
        delta_distance = distance_travelled - previous_distance_travelled;
        
		if (inertial.get_accel().x > 0.1 || inertial.get_accel().y > 0.1) {
			// std trig functions are in radians, so we have intermediary conversion to radians
        	x += delta_distance * std::cos(to_rad(heading));
        	y += delta_distance * std::sin(to_rad(heading));
		}

        // At the end of the loop, set previous_distance_travelled for the next loop iteration
        previous_distance_travelled = distance_travelled;

		// print for debugging
		chassis.setPose(x, y, theta);
		printf("X: %f, Y: %f, Theta: %f, %f\n", x, y, get_dt_heading(), get_imu_rotation());

        pros::delay(10); // todo
    }
}