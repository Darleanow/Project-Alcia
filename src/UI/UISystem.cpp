#include "UISystem.h"
#include "SystemRelated.h"

#include <cstdio>
#include <iostream>

UISystem::UISystem()  = default;
UISystem::~UISystem() = default;

void UISystem::greet() const
{
  std::cout << color(ColorType::RED) << "Project: Alcia\n"
            << color(ColorType::DEFAULT);
  std::cout << color(ColorType::LYELLOW) << "Greetings, Traveler !\n"
            << color(ColorType::DEFAULT);
}

void UISystem::display_rules() const
{
  std::cout << "============= RULES ==================" << std::endl;
  std::cout << "- Cheating is prohibited, you can't anyways." << std::endl;
  std::cout << "- Earn gold and xp by killing monsters." << std::endl;
  std::cout << "- When killing monsters, you have a 30% rate of getting a "
               "random piece of stuff"
            << std::endl;
  std::cout
      << "- Get items using gold in Town (shop) or craft them (black-smith)"
      << std::endl;
  std::cout
      << "- Leveling up fills up your health points, potions can do it too..."
      << std::endl;
  std::cout << "- You might wanna check Shop and Forge sometimes, items gets "
               "better depending on your level !"
            << std::endl;
  std::cout << "- You die, it's the end, no saves, no control+z !" << std::endl;
  std::cout << "- There are a few colors that you will see:" << std::endl;
  std::cout << "    -> " << color(ColorType::GREEN) << "Green"
            << color(ColorType::DEFAULT) << " is " << color(ColorType::GREEN)
            << "Common" << color(ColorType::DEFAULT) << std::endl;
  std::cout << "    -> " << color(ColorType::BLUE) << "Blue"
            << color(ColorType::DEFAULT) << " is " << color(ColorType::BLUE)
            << "Rare" << color(ColorType::DEFAULT) << std::endl;
  std::cout << "    -> " << color(ColorType::RED) << "Purple"
            << color(ColorType::DEFAULT) << " is " << color(ColorType::RED)
            << "Epic" << color(ColorType::DEFAULT) << std::endl;
  std::cout << "    -> " << color(ColorType::YELLOW) << "Yellow"
            << color(ColorType::DEFAULT) << " is " << color(ColorType::YELLOW)
            << "Legendary" << color(ColorType::DEFAULT) << std::endl;
  std::cout << "If u didn't read those rules, may the great Azeael gets you to "
               "perish. . ."
            << std::endl;
  std::cout << std::endl << "Get ready and press Enter to begin. . .";
  getchar();
}
