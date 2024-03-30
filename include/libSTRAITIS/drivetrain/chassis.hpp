#pragma once
#include "main.h"

namespace strait
{
	void moveRaw(int voltage, int time);
	void calibrateIMU();

	void odomThread();
}