#include "main.h"

#include <vector>
#include <numeric>  // for std::accumulate

namespace strait
{
	double vector_average(const std::vector<double>& v) {
	    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
	}

	double getMotorDistanceTraveled() { 
		return (float(leftDrive.at(1).get_position()) * 2.75 * M_PI / 360); }
}

