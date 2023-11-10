#include "main.h"

void cycleGradient(pros::adi::Led& ledname, std::string color1, std::string color2, int speed) {
  static int shift = 0;
  uint32_t color1Hex = std::stoul(color1.substr(1), nullptr, 16);
  uint32_t color2Hex = std::stoul(color2.substr(1), nullptr, 16);
  for (int i = 0; i < 64; i++) {
    uint8_t blendAmount = (uint8_t)(256L * (i + shift) / 64);
    uint32_t blendedColor = blend(color1Hex, color2Hex, blendAmount);
    ledname.set_pixel(blendedColor, i);
  }
  pros::delay(speed);
  shift = (shift + 1) % 64;
}

uint32_t blend(uint32_t color1, uint32_t color2, uint8_t blendAmount) {
  uint8_t r1 = (color1 >> 16) & 0xFF;
  uint8_t g1 = (color1 >> 8) & 0xFF;
  uint8_t b1 = color1 & 0xFF;

  uint8_t r2 = (color2 >> 16) & 0xFF;
  uint8_t g2 = (color2 >> 8) & 0xFF;
  uint8_t b2 = color2 & 0xFF;

  uint8_t r = r1 + (r2 - r1) * blendAmount / 255;
  uint8_t g = g1 + (g2 - g1) * blendAmount / 255;
  uint8_t b = b1 + (b2 - b1) * blendAmount / 255;

  return (r << 16) | (g << 8) | b;
}