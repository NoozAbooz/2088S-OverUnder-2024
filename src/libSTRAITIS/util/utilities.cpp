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

	float toRad(float angle_deg){
	  return(angle_deg/(180.0/M_PI));
	}

	float toDeg(float angle_rad){
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

	void led::gradient(std::uint32_t start_color, std::uint32_t end_color, int fade_width,
                       int start_pos, bool reverse) {
    	if (fade_width == 0) {
    	    fade_width = 64;
    	}
    	for (int i = 0; i < fade_width; i++) {
    	    light[start_pos + i] = interpolate_rgb(start_color, end_color, i, fade_width);
    	}
	}

	led::rgb led::hex_to_rgb(std::uint32_t color) {
    	rgb in;
    	in.r = (color >> 16) & 0xff;
    	in.g = (color >> 8) & 0xff;
    	in.b = color & 0xff;
    	return in;
	}

	std::uint32_t led::interpolate_rgb(std::uint32_t start_color, std::uint32_t end_color, int step,
                                       int fade_width) {
    rgb startComponents = hex_to_rgb(start_color);
    rgb endComponents = hex_to_rgb(end_color);

    double red_diff = endComponents.r - startComponents.r;
    double green_diff = endComponents.g - startComponents.g;
    double blue_diff = endComponents.b - startComponents.b;

    double red_step = red_diff / fade_width;
    double green_step = green_diff / fade_width;
    double blue_step = blue_diff / fade_width;

    rgb solved;

    solved.r = (startComponents.r + red_step * step);
    solved.g = (startComponents.g + green_step * step);
    solved.b = (startComponents.b + blue_step * step);
    return rgb_to_hex(solved.r, solved.g, solved.b);
}
}

