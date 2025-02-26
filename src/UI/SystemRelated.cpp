#include "SystemRelated.h"

#include <ctime>
#include <random>
#include <cstdlib>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
void cls()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	  /* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	  /* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
#else
#include <unistd.h>
#include <term.h>

void cls()
{
  system("clear");
}
#endif

int generate_random_number(int min, int max)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max); // define the range

	return distr(gen);
}

bool roll_boolDice(int succes_percentage)
{
	//1.0f means float instead of double so less memory consumed ^^
	float f = rand() * 1.0f / static_cast<float>(RAND_MAX);
	float vv = succes_percentage / 10.0f;
	return f < vv;
}

bool is_digits(const std::string& str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

std::string get_color_from_rarity(std::string rarity)
{
  if (rarity == "Common" || rarity == "common")
  {
    return "green";
  }
  
  if (rarity == "Rare" || rarity == "rare")
  {
    return "blue";
  }

  if (rarity == "Epic" || rarity == "epic")
  {
    return "red";
  }

  if (rarity == "Legendary" || rarity == "legendary")
  {
    return "yellow";
  }

  return "def";
}

ColorType get_color_from_string(std::string color)
{
  if (color == "green")
  {
    return ColorType::GREEN;
  }

  if (color == "blue")
  {
    return ColorType::BLUE;
  }

  if (color == "red")
  {
    return ColorType::RED;
  }

  if (color == "yellow")
  {
    return ColorType::YELLOW;
  }

  return ColorType::DEFAULT;
}

std::string color(ColorType color_type)
{
  switch(color_type)
  {
    case ColorType::DEFAULT:
      return "\x1b[0m";
    case ColorType::GREEN:
      return "\x1b[32m";
    case ColorType::YELLOW:
      return "\x1b[33m";
    case ColorType::BLUE:
      return "\x1b[34m";
    case ColorType::RED:
      return "\x1b[35m";
    case ColorType::LYELLOW:
      return "\x1b[94m";
    default:
      return "";
  }

  return "";
}

#ifdef _WIN32
bool EnableVTMode()
{
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return false;
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hOut, dwMode))
	{
		return false;
	}
	return true;
}
bool fSuccess = EnableVTMode();
#endif
