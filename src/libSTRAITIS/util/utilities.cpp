#include "abstractGlobals.hpp"
#include "main.h"

#include <vector>
#include <numeric>  // for std::accumulate
#include <algorithm>
#include <deque>


namespace strait
{
	double vector_average(const std::vector<double>& v) {
	    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
	}

	double median_filter(std::deque<double>& buffer, double newVal, int windowSize) {
    	buffer.push_back(newVal);
    	if (buffer.size() > windowSize) {
    	    buffer.pop_front();
    	}
	
    	std::vector<double> data(buffer.begin(), buffer.end());
    	std::sort(data.begin(), data.end());
	
    	return data[windowSize / 2];
	}

	// prolly dont use this 💀
	double tripleIMUHeading(double heading1, double heading2, double heading3, double threshold) { 
		// Run through median filter
        int windowSize = 20;
		std::deque<double> buffer1;
		std::deque<double> buffer2;
		std::deque<double> buffer3;

		heading1 = strait::median_filter(buffer1, heading1, windowSize);
		heading2 = strait::median_filter(buffer2, heading2, windowSize);
		heading3 = strait::median_filter(buffer3, heading3, windowSize);

	    // Calculate the absolute differences between the headings
	    double diff12 = std::abs(heading1 - heading2);
	    double diff23 = std::abs(heading2 - heading3);
	    double diff13 = std::abs(heading1 - heading3);

	    // Check if one of the sensors is drifting
	    if (diff12 > threshold && diff13 > threshold) {
	        // Sensor 1 is drifting, return mean of sensor 2 and 3
	        return (heading2 + heading3) / 2.0;
	    } else if (diff12 > threshold && diff23 > threshold) {
	        // Sensor 2 is drifting, return mean of sensor 1 and 3
	        return (heading1 + heading3) / 2.0;
	    } else if (diff23 > threshold && diff13 > threshold) {
	        // Sensor 3 is drifting, return mean of sensor 1 and 2
	        return (heading1 + heading2) / 2.0;
	    } else {
	        // No sensor is drifting, return mean of all sensors 
			// (or all of them are drifing and we just gotta pray 💀)
	        return (heading1 + heading2 + heading3) / 3.0;
	    }
	}

	bool isDriverControl() {
    	return pros::competition::is_connected() && !pros::competition::is_autonomous() && !pros::competition::is_disabled();
	}

	float reduce_0_to_360(float angle) {
	  while(!(angle >= 0 && angle < 360)) {
	    if( angle < 0 ) { angle += 360; }
	    if(angle >= 360) { angle -= 360; }
	  }
	  return(angle);
	}

	float reduce_negative_180_to_180(float angle) {
	  while(!(angle >= -180 && angle < 180)) {
	    if( angle < -180 ) { angle += 360; }
	    if(angle >= 180) { angle -= 360; }
	  }
	  return(angle);
	}

	float reduce_negative_90_to_90(float angle) {
	  while(!(angle >= -90 && angle < 90)) {
	    if( angle < -90 ) { angle += 180; }
	    if(angle >= 90) { angle -= 180; }
	  }
	  return(angle);
	}

	double to_rad(double angle_deg){
	  return(angle_deg/(180.0/M_PI));
	}

	double to_deg(double angle_rad){
	  return(angle_rad*(180.0/M_PI));
	}

	float clamp(float input, float min, float max){
	  if( input > max ){ return(max); }
	  if(input < min){ return(min); }
	  return(input);
	}

	bool isReversed(double input){
	  if(input<0) return(true);
	  return(false);
	}

	float to_milivolt(float input){
	  return(input * (12000.0/127.0));
	}

	float deadband(float input, float width){
	  if (fabs(input)<width){
	    return(0);
	  }
	  return(input);
	}

	void writeIntToFile(int num) {
    	FILE *save_file;
    	char buffer[51]; // 50 bytes for data, 1 byte for '\0'

    	if (num != -1) { // If num is not -1, write it to the file
    	    save_file = fopen("/usd/auton.txt", "w");
    	    if (save_file != NULL) {
    	        fprintf(save_file, "%d", num);
    	        fclose(save_file);
    	    } else {
    	        printf("Error opening file for writing\n");
    	    }
    	}
	}

	void tuneDriveCurve() {
		int rotCurve = 1;
		
		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
			int rotCurve = rotCurve + 0.1;
		} else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			int rotCurve = rotCurve - 0.1;
		}
		printf("Rotational Curve: %d\n", rotCurve);
		strait::arcadeDrive(12, rotCurve, 1);
	}
}

