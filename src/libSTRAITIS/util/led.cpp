#include "deviceGlobals.hpp"
#include "main.h"

#include <vector>
#include <numeric>  // for std::accumulate
#include <algorithm>
#include <deque>


namespace strait
{
	led::rgb led::hex_to_rgb(std::uint32_t color) {
    	rgb in;
    	in.r = (color >> 16) & 0xff;
    	in.g = (color >> 8) & 0xff;
    	in.b = color & 0xff;
    	return in;
	}

	std::uint32_t led::rgb_to_hex(int r, int g, int b) {
    	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
	}

	void led::gradient(std::uint32_t start_color, std::uint32_t end_color, int fade_width,
                       int start_pos, bool reverse) {
    	if (fade_width == 0) {
    	    fade_width = 64;
    	}
    	for (int i = 0; i < fade_width; i++) {
    	    lightStrip[start_pos + i] = interpolate_rgb(start_color, end_color, i, fade_width);
    	}
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