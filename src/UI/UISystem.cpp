#include "UISystem.h"
#include "Utils/DrawUtils.h"

#include <algorithm>
#include <cstdio>
#include <iostream>

UISystem::UISystem()  = default;
UISystem::~UISystem() = default;

static inline void set_cursor_pos(int x, int y)
{
  std::cout << "\033[" << y << ";" << x << "H";
}

void UISystem::greet() const
{
  set_cursor_pos(0, 0);
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
            << "random piece of stuff" << std::endl;
  std::cout
      << "- Get items using gold in Town (shop) or craft them (black-smith)"
      << std::endl;
  std::cout
      << "- Leveling up fills up your health points, potions can do it too..."
      << std::endl;
  std::cout << "- You might wanna check Shop and Forge sometimes, items gets "
            << "better depending on your level !" << std::endl;
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

void UISystem::display_informations_of_current_location(
    std::shared_ptr<Location> location
)
{
  Utils::clear_screen();
  std::cout << "[" << color(ColorType::BLUE) << location->get_name()
            << color(ColorType::DEFAULT) << "]\n";
  std::cout << location->get_description() << "\n\n";
}

void UISystem::display_actions_for_current_location(
    std::shared_ptr<Location> location
)
{
  int index = 1;

  for(const auto &action : location.get()->get_location_actions()) {
    std::cout << "[" << index << "] " << action.get()->get_name() << std::endl;
    index++;
  }
}

int UISystem::prompt_user_for_index_selection(Range range)
{
  std::cout << '>';
  std::string selected_string;

  int         selected = -1;
  std::getline(std::cin, selected_string);
  if(!selected_string.empty() &&
     !std::all_of(selected_string.begin(), selected_string.end(), isspace)) {
    selected = std::stoi(selected_string);
  }

  while(static_cast<size_t>(selected) < range.begin ||
        static_cast<size_t>(selected) > range.end) {
    std::cout << color(ColorType::RED)
              << "Error: Invalid input. It must be between " << range.begin
              << " and " << range.end << ". (Your input: " << selected_string
              << ")" << color(ColorType::DEFAULT) << '\n';

    std::cout << '>';
    std::getline(std::cin, selected_string);

    if(!selected_string.empty() &&
       !std::all_of(selected_string.begin(), selected_string.end(), isspace)) {
      selected = std::stoi(selected_string);
    }
  }

  return selected;
}
