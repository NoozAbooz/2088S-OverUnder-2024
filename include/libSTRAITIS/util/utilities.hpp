#pragma once
#include "main.h"

namespace strait
{
    double vector_average(const std::vector<double>& v);
    double medianFilter(std::deque<double>& buffer, double newVal, int windowSize);
    float toMilivolt(float input);
}