#pragma once
#include "main.h"

namespace strait
{
    double vector_average(const std::vector<double>& v);
    double median_filter(std::deque<double>& buffer, double newVal, int windowSize);
    float to_milivolt(float input);
    bool isDriverControl();
}