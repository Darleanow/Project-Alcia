#include "Hero.h"
#include "system_related.h"
#include <conio.h>
#include <windows.h>

#include "Monster.h"
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

int main()
{
	Hero player;
	std::cout << color("def");
	std::cout << "[PROJECT:ALCIA]" << std::endl << std::endl;
	std::cout << "Hello traveler !" << std::endl;
	std::cout << "Tell me your name please . . ." << std::endl;
	std::cout << "name >";
	std::string temp_name;
	std::cin >> temp_name;
	std::cout << std::endl;
	player.set_name(temp_name);

	std::cout << "Okay " << player.get_name() << ". \nRules:" << std::endl;
	std::cout << "- Cheating is prohibited, you can't anyways." << std::endl;
	std::cout << "- Earn gold and xp by killing monsters." << std::endl;
	std::cout << "- When killing monsters, you have a 30% rate of getting a random piece of stuff" << std::endl;
	std::cout << "- Get items using gold in Town (shop) or craft them (black-smith)" << std::endl;
	std::cout << "- Leveling up fills up your health points, potions can do it too..." << std::endl;
	std::cout << "- You might wanna check Shop and Forge sometimes, items gets better depending on your level !" << std::endl;
	std::cout << "- You die, it's the end, no saves, no control+z !" << std::endl;
	std::cout << "- There are a few colors that you will see:" << std::endl;
	std::cout << "    -> " << color("common") << "Green" << color("def") << " is " << color("common") << "Common" << color("def") << std::endl;
	std::cout << "    -> " << color("rare") << "Blue" << color("def") << " is " << color("rare") << "Rare" << color("def") << std::endl;
	std::cout << "    -> " << color("epic") << "Purple" << color("def") << " is " << color("epic") << "Epic" << color("def") << std::endl;
	std::cout << "    -> " << color("legendary") << "Yellow" << color("def") << " is " << color("legendary") << "Legendary" << color("def") << std::endl;
	std::cout << "If u didn't read those rules, may the great Azeael gets you to perish. . ." << std::endl;
	std::cout << std::endl << "Get ready and press Enter to begin. . .";
	_getch();
	cls();
	
	//game loop, Easy as hello ^^
	while (player.get_hp() > 0)
	{
		player.display_actions();
	}
}
