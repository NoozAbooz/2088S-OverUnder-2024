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

	double medianFilter(std::deque<double>& buffer, double newVal, int windowSize) {
    	buffer.push_back(newVal);
    	if (buffer.size() > windowSize) {
    	    buffer.pop_front();
    	}
	
    	std::vector<double> data(buffer.begin(), buffer.end());
    	std::sort(data.begin(), data.end());
	
    	return data[windowSize / 2];
	}

	double getMotorDistanceTraveled() { 
		return (float(leftDrive.at(1).get_position()) * 2.75 * M_PI / 360); 
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

	float toMilivolt(float input){
	  return(input * (12000.0/127.0));
	}

	float deadband(float input, float width){
	  if (fabs(input)<width){
	    return(0);
	  }
	  return(input);
	}
}

