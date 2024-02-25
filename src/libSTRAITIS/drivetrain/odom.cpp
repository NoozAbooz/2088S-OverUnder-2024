#include "main.h"

namespace strait
{
	float angleError(float angle1, float angle2, bool radians) {
    	return std::remainder(angle1 - angle2, radians ? 2 * M_PI : 360);
	}
}
