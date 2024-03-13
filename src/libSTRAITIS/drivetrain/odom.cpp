#include "main.h"

using namespace strait;

double    global_robot_x; // global X
double    global_robot_y; // global Y
double    globalTheta;    // global theta

Position odom_pos;

double getMotorDistanceTraveled() { 
		double avgPosition = (leftDrive.at(1).get_position() + rightDrive.at(1).get_position()) / 2;
		return (float(avgPosition) * 3.25 * M_PI / 360); 
	}

int current_robot_heading() {
  globalTheta = (inertial.get_heading());
  return globalTheta; 
}

