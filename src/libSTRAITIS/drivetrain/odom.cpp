#include "main.h"
#include "pros/rtos.hpp"

using namespace strait;

double    x = 0; // global X
double    y = 0; // global Y
double    theta; // global theta

Position odom_pos;

// Gyro scale effect from 2775V
// If it is a bit less than 360, that's your number. If it is a bit more than 0, add 360 and that's your number.
double gyro_scale1 = 357.91;
double gyro_scale2 = 360.8;

double wheel_diameter = 3.25;
double track_width = 10.75;

double get_imu_rotation() {
	double rotation1 = inertial.get_rotation();
	double rotation2 = inertial2.get_rotation();

	double average_rotation = ((rotation1 * (360.0 / gyro_scale1)) + (rotation2 * (360.0 / gyro_scale2))) / 2;
	return average_rotation;
}

double get_dt_distance_traveled() { 
	double avg_position = (leftDrive.at(1).get_position() + rightDrive.at(1).get_position()) / 2;
	return (avg_position / 360) * (M_PI * wheel_diameter) * (42.0/48.0);
}

// double get_dt_heading() {
// 	double wheel_circumference = M_PI * wheel_diameter;

// 	double left_distance = (leftDrive.at(1).get_position() / 360) * wheel_circumference / gear_ratio;
// 	double right_distance = (rightDrive.at(1).get_position() / 360) * wheel_circumference / gear_ratio;

// 	double heading_in_radians = (left_distance - right_distance) / track_width;
// 	return std::fmod(to_deg(heading_in_radians), 360);
// }

void strait::odomThread() {
	double avg_heading;
	double previous_distance_traveled;
	double delta_distance;
	double heading;
	double distance_traveled;

	while (true) {
		// Find average between dt and imu heading
		// wrap to [0, 360)
		heading = fmod(get_imu_rotation() - 90, 360);
		while (heading < 0) {
    		heading += 360;
  		}
  		while (heading > 360) {
    		heading -= 360;
  		}

		distance_traveled = get_dt_distance_traveled();
        
		if (inertial.get_accel().x > 0.1 || inertial.get_accel().y > 0.1) {
			delta_distance = distance_traveled - previous_distance_traveled;
			// std trig functions are in radians, so we have intermediary conversion to radians
        	x += delta_distance * std::cos(to_rad(heading));
        	y += delta_distance * std::sin(to_rad(heading));

			// Set previous_distance_travelled for the next loop iteration
        	previous_distance_traveled = distance_traveled;
		}

		// print for debugging
		chassis.setPose(chassis.getPose().x, chassis.getPose().y, get_imu_rotation());
		printf("X: %f, Y: %f, Theta: %f\n", x, y, get_imu_rotation());

        pros::delay(2); // todo
    }
}