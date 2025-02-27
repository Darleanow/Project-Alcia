#pragma once
#include <iostream>

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

void        cls();

int         generate_random_number(int min, int max);

bool        roll_boolDice(int succes_percentage);

std::string get_color_from_rarity(std::string rarity);
ColorType   get_color_from_string(std::string color);

std::string color(ColorType color_type);

bool        is_digits(const std::string &str);
