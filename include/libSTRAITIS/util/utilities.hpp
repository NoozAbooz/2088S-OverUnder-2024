#pragma once
#include "main.h"

namespace strait
{
    double vector_average(const std::vector<double>& v);
    double median_filter(std::deque<double>& buffer, double newVal, int windowSize);
    float to_milivolt(float input);
    bool isDriverControl();

    namespace led
    {
        typedef struct {
            double r;
            double g;
            double b;
        } rgb;

        void gradient(std::uint32_t start_color, std::uint32_t end_color, int fade_width,
                      int start_pos, bool reverse);
        rgb hex_to_rgb(std::uint32_t color);
        std::uint32_t rgb_to_hex(int r, int g, int b);
        std::uint32_t interpolate_rgb(std::uint32_t start_color, std::uint32_t end_color, int step,
                                       int fade_width);
    }
}