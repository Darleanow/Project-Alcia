#include "system_related.h"

#include <ctime>
#include <random>


#pragma once

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
	if (!cur_term)
	{
		int result;
		setupterm(NULL, STDOUT_FILENO, &result);
		if (result <= 0) return;
	}

	putp(tigetstr("clear"));
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
	float f = rand() * 1.0f / RAND_MAX;
	float vv = succes_percentage / 10.0f;
	return f < vv;
}

bool is_digits(const std::string& str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

//COLORED TEXT
std::string color(std::string attr)
{
	if (attr == "common" || attr == "Common")
	{
		return "\x1b[32m";
	}
	else if (attr == "red")
	{
		return "\x1b[31m";
	}
	else if (attr == "epic" || attr == "Epic")
	{
		return "\x1b[35m";
	}
	else if (attr == "rare" || attr == "Rare")
	{
		return "\x1b[34m";
	}
	else if (attr == "def")
	{
		return "\x1b[0m";
	}
	else if (attr == "legendary" || attr == "Legendary")
	{
		return "\x1b[33m";
	}
	else if (attr == "l_yellow")
	{
		return "\x1b[93m";
	}
	else if (attr == "potion")
	{
		return "\x1b[94m";
	}
	else
	{
		return "";
	}
}