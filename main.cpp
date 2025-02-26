#include "src/Hero.h"
#include "src/UI/SystemRelated.h"
#include "src/UI/UISystem.h"
#include <stdio.h>

int main()
{
  UISystem user_interface;

  Hero player;
	
	std::cout << color(ColorType::DEFAULT) << "[PROJECT:ALCIA]" << std::endl << std::endl;
	std::cout << "Hello traveler !" << std::endl;
	std::cout << "Tell me your name please . . ." << std::endl;
	std::cout << "name >";
	
  std::string temp_name;
  std::getline(std::cin, temp_name);
	player.set_name(temp_name);

  user_interface.display_rules();
  getchar();
  cls();
	
	while (player.get_hp() > 0)
	{
		player.display_actions();
	}
}

