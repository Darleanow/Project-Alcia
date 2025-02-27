#include "SystemRelated.h"

#include <cstdlib>
#include <ctime>
#include <random>

int generate_random_number(int min, int max)
{
  std::random_device              rd;
  std::mt19937                    gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  return distr(gen);
}

bool roll_boolDice(int succes_percentage)
{
  float f  = rand() * 1.0f / static_cast<float>(RAND_MAX);
  float vv = succes_percentage / 10.0f;
  return f < vv;
}

bool is_digits(const std::string &str)
{
  return str.find_first_not_of("0123456789") == std::string::npos;
}

std::string get_color_from_rarity(std::string rarity)
{
  if(rarity == "Common" || rarity == "common") {
    return "green";
  }

  if(rarity == "Rare" || rarity == "rare") {
    return "blue";
  }

  if(rarity == "Epic" || rarity == "epic") {
    return "red";
  }

  if(rarity == "Legendary" || rarity == "legendary") {
    return "yellow";
  }

  return "";
}

ColorType get_color_from_string(std::string color)
{
  if(color == "green") {
    return ColorType::GREEN;
  }

  if(color == "blue") {
    return ColorType::BLUE;
  }

  if(color == "red") {
    return ColorType::RED;
  }

  if(color == "yellow") {
    return ColorType::YELLOW;
  }

  return ColorType::DEFAULT;
}

std::string color(ColorType color_type)
{
  switch(color_type) {
  case ColorType::DEFAULT:
    return "\x1b[0m";
  case ColorType::RED:
    return "\x1b[31m";
  case ColorType::GREEN:
    return "\x1b[32m";
  case ColorType::YELLOW:
    return "\x1b[33m";
  case ColorType::BLUE:
    return "\x1b[34m";
  case ColorType::MAGENTA:
    return "\x1b[35m";
  case ColorType::CYAN:
    return "\x1b[36m";
  case ColorType::LYELLOW:
    return "\x1b[93m";
  default:
    return "";
  }

  return "";
}
