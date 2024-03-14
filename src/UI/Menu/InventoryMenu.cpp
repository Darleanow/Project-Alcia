#include "InventoryMenu.h"
#include "../Utils/DrawUtils.h"

#include <cstdio>
#include <iostream>

InventoryMenu::InventoryMenu(std::shared_ptr<Hero> player)
    : m_player(std::move(player))
{
}

void InventoryMenu::execute()
{
  draw_gui();
  getchar();
}

void InventoryMenu::draw_gui() const
{
  Utils::clear_screen();
  std::cout << "[" << color(ColorType::BLUE) << "Inventory & Stats"
            << color(ColorType::DEFAULT) << "]\n";

  std::cout << "[" << color(ColorType::BLUE) << "Stats"
            << color(ColorType::DEFAULT) << "]\n";

  std::cout << "Player name: " << color(ColorType::LYELLOW)
            << m_player->get_name() << color(ColorType::DEFAULT) << '\n';
  std::cout << "Level: " << color(ColorType::CYAN) << m_player->get_level()
            << color(ColorType::DEFAULT) << '\n';
  std::cout << "Health: " << color(ColorType::GREEN) << m_player->get_hp()
            << color(ColorType::DEFAULT) << " / " << color(ColorType::GREEN)
            << m_player->get_max_hp() << color(ColorType::DEFAULT) << '\n';
  std::cout << "Attack: " << color(ColorType::RED) << m_player->get_atk()
            << color(ColorType::DEFAULT) << "\n\n";

  std::cout << "[" << color(ColorType::BLUE) << "Inventory"
            << color(ColorType::DEFAULT) << "]\n";

  int index = 1;
  if(m_player->get_inventory().empty()) {
    std::cout << "Your inventory is currently empty...\n";
  }

  for(const auto &item : m_player->get_inventory()) {
    std::cout << index << ". "
              << color(get_color_from_string(
                     get_color_from_rarity(item->get_rarity())
                 ))
              << item->get_name() << color(ColorType::DEFAULT) << " x "
              << item->get_quantity() << color(ColorType::DEFAULT) << "\n";

    index++;
  }
}
