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
  float f  = static_cast<float>(rand()) * 1.0f / static_cast<float>(RAND_MAX);
  float vv = static_cast<float>(succes_percentage) / 10.0f;
  return f < vv;
}

bool is_digits(const std::string &str)
{
  return str.find_first_not_of("0123456789") == std::string::npos;
}
