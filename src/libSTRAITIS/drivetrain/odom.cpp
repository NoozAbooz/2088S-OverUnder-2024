#include "deviceGlobals.hpp"
#include "main.h"

using namespace strait;

double    x = 0; // global X
double    y = 0; // global Y
double    theta; // global theta

Position odom_pos;

// Gyro scale effect from 2775V
// If it is a bit less than 360, that's your number. If it is a bit more than 0, add 360 and that's your number.
double gyro_scale1 = 360.0;
double gyro_scale2 = 360.0;

constexpr double wheel_radius = (3.25 / 2.0);
constexpr double gear_ratio = (36.0 / 48.0);
constexpr double track_width = 11.5;

double get_dt_distance_traveled() { 
	constexpr double wheel_circumference = 2 * M_PI * wheel_radius;
	double avg_position = (leftDrive.at(0).get_position() + rightDrive.at(0).get_position()) / 2;
	return ((avg_position / 360) * wheel_circumference * gear_ratio);
}

double get_imu_heading() {
	double start_heading = 90;
	double heading1 = std::fmod((360 - inertial.get_rotation()) + start_heading, 360);
	double heading2 = std::fmod((360 - inertial.get_rotation()) + start_heading, 360);

	// apply gyro offset and find average between two imus
	return ((heading1 * (360.0 / gyro_scale1)) + (heading2 * (360.0 / gyro_scale2))) / 2;
}

double get_dt_heading() {
	constexpr double wheel_circumference = 2 * M_PI * wheel_radius;
	double start_heading = 90;

	double left_distance = (leftDrive.at(1).get_position() / 360) * wheel_circumference * gear_ratio;
	double right_distance = (rightDrive.at(1).get_position() / 360) * wheel_circumference * gear_ratio;

	double heading_in_radians = (right_distance - left_distance) / track_width;
	return std::fmod((360 - strait::to_deg(heading_in_radians)) + start_heading, 360);
}

void strait::odomThread() {
	leftDrive.tare_position();
	rightDrive.tare_position();

	inertial.set_heading(0);
	inertial2.set_heading(0);

	double previous_distance_traveled = 0;
	while (true) {
		// Find average between dt and imu heading
		double heading = get_imu_heading();
		double distance_traveled = get_dt_distance_traveled();

        double change_in_distance = distance_traveled - previous_distance_traveled;
        
		// std trig functions are in radians, so we have intermediary conversion to radians
        x += change_in_distance * std::cos(to_rad(heading));
        y += change_in_distance * std::sin(to_rad(heading));

        // At the end of the loop, set previous_distance_traveled for the next loop iteration
        previous_distance_traveled = distance_traveled;

		// print for debugging
		printf("X: %f, Y: %f, Theta: %f\n", x, y, heading);
		chassis.setPose(x, y, heading);

        pros::delay(100);
    }
}