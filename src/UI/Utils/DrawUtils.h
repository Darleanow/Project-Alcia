#pragma once
#include <cstdlib>
#include <string>

namespace Utils {

void clear_screen();
} // namespace Utils

enum class ColorType
{
  DEFAULT,
  RED,
  GREEN,
  BLUE,
  MAGENTA,
  CYAN,
  YELLOW,
  LGREEN,
  LBLUE,
  LRED,
  LYELLOW
};

ColorType   get_color_from_string(std::string color);
std::string get_color_from_rarity(std::string rarity);
std::string color(ColorType color_type);
