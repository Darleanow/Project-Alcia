#include "InventoryStatsMenu.h"
#include "../../Core/CoreUtils.h"
#include "../UISystem.h"
#include "../Utils/DrawUtils.h"

#include <cstdio>
#include <iostream>
#include <stdexcept>

InventoryStatsMenu::InventoryStatsMenu(const std::shared_ptr<Hero> player)
    : AMenu(player)
{
}

void InventoryStatsMenu::execute()
{
  Utils::clear_screen();

  draw_gui();

  std::cout << "\n\n";

  show_actions();

  UISystem ui_system;
  Range    range  = {.begin = 1, .end = 5};
  int      result = ui_system.prompt_user_for_index_selection(range);

  switch(result) {
  case 1:
    equip_item();
    break;
  case 2:
    unequip_item();
    break;
  case 3:
    use_item();
    break;
  case 4:
    throw_item();
    break;
  case 5:
    break;
  default:
    throw std::runtime_error("Uknown validated Index.");
    break;
  }
}

void InventoryStatsMenu::draw_gui() const
{
  std::cout << "[" << color(ColorType::BLUE) << "Stats"
            << color(ColorType::DEFAULT) << "]\n\n";

  std::cout << "- Health: " << color(ColorType::RED)
            << m_player->m_stats->get_stats().health
            << color(ColorType::DEFAULT) << "/" << color(ColorType::RED)
            << m_player->m_stats->get_stats().max_health
            << color(ColorType::DEFAULT) << '\n';

  std::cout << "- Attack: " << color(ColorType::LYELLOW)
            << m_player->m_stats->get_stats().attack
            << color(ColorType::DEFAULT) << "\n";

  std::cout << "- Critical rate: " << color(ColorType::GREEN)
            << m_player->m_stats->get_stats().crit_rate << "%"
            << color(ColorType::DEFAULT) << "\n\n\n";

  std::cout << "[" << color(ColorType::BLUE) << "Equipment"
            << color(ColorType::DEFAULT) << "]\n\n";

  const auto &primary_hand_item =
      m_player->m_equipment->get_item(EquipmentLocation::PrimaryHand);
  std::cout << "- Primary hand: "
            << (primary_hand_item
                    ? color(get_color_from_string(
                          get_color_from_rarity(primary_hand_item->get_rarity())
                      )) + primary_hand_item->get_name()
                    : color(ColorType::YELLOW) + "No equipped item.")
            << color(ColorType::DEFAULT) << '\n';

  const auto &helmet_item =
      m_player->m_equipment->get_item(EquipmentLocation::Helmet);
  std::cout << "- Helmet: "
            << (helmet_item
                    ? color(get_color_from_string(
                          get_color_from_rarity(helmet_item->get_rarity())
                      )) + helmet_item->get_name()
                    : color(ColorType::YELLOW) + "No equipped item.")
            << color(ColorType::DEFAULT) << '\n';

  const auto &chestplate_item =
      m_player->m_equipment->get_item(EquipmentLocation::Chestplate);
  std::cout << "- Chestplate: "
            << (chestplate_item
                    ? color(get_color_from_string(
                          get_color_from_rarity(chestplate_item->get_rarity())
                      )) + chestplate_item->get_name()
                    : color(ColorType::YELLOW) + "No equipped item.")
            << color(ColorType::DEFAULT) << '\n';

  const auto &leggings_item =
      m_player->m_equipment->get_item(EquipmentLocation::Leggings);
  std::cout << "- Leggings: "
            << (leggings_item
                    ? color(get_color_from_string(
                          get_color_from_rarity(leggings_item->get_rarity())
                      )) + leggings_item->get_name()
                    : color(ColorType::YELLOW) + "No equipped item.")
            << color(ColorType::DEFAULT) << '\n';

  const auto &boots_item =
      m_player->m_equipment->get_item(EquipmentLocation::Boots);
  std::cout << "- Boots: "
            << (boots_item ? color(get_color_from_string(
                                 get_color_from_rarity(boots_item->get_rarity())
                             )) + boots_item->get_name()
                           : color(ColorType::YELLOW) + "No equipped item.")
            << color(ColorType::DEFAULT) << "\n\n\n";

  std::cout << "[" << color(ColorType::BLUE) << "Inventory"
            << color(ColorType::DEFAULT) << "]\n\n";

  if(m_player->m_inventory->get_items().empty()) {
    std::cout << color(ColorType::LYELLOW) << "No items in inventory.\n"
              << color(ColorType::DEFAULT);
  }

  int id = 1;
  for(const auto &item_stack : m_player->m_inventory->get_items()) {
    std::cout << id << ". "
              << color(get_color_from_string(
                     get_color_from_rarity(item_stack.item->get_rarity())
                 ))
              << item_stack.item->get_name() << color(ColorType::DEFAULT)
              << " x " << item_stack.quantity << '\n';
    ++id;
  }
}

void InventoryStatsMenu::show_actions() const
{
  std::cout << "[1] Equip something\n";
  std::cout << "[2] Unequip a piece of equipment \n";
  std::cout << "[3] Use an item\n";
  std::cout << "[4] Throw an item\n";
  std::cout << "[5] Go back\n";
}

// TODO(Darleanow): Move below in a manager

void InventoryStatsMenu::equip_item()
{
  Utils::clear_screen();

  std::cout << "[" << color(ColorType::BLUE) << "Available Items"
            << color(ColorType::DEFAULT) << "]\n\n";

  std::vector<size_t> equippable_indices;
  size_t              display_index = 0;

  const auto         &items = m_player->m_inventory->get_items();
  for(size_t i = 0; i < items.size(); ++i) {
    const auto &item_stack         = items[i];
    const auto &type               = item_stack.item->get_type();
    const auto &equipment_location = CoreUtils::to_equipment_location(type);

    if(equipment_location &&
       m_player->m_equipment->validate_slot(*equipment_location)) {
      display_index++;
      std::cout << "[" << display_index << "] "
                << color(get_color_from_string(
                       get_color_from_rarity(item_stack.item->get_rarity())
                   ))
                << item_stack.item->get_name() << color(ColorType::DEFAULT)
                << " x" << item_stack.quantity << '\n';

      equippable_indices.push_back(i);
    }
  }

  if(equippable_indices.empty()) {
    std::cout << color(ColorType::RED) << "No items available for equipping."
              << color(ColorType::DEFAULT) << std::endl;
    return;
  }

  UISystem ui_system;
  Range    range  = {.begin = 1, .end = display_index};
  int      result = ui_system.prompt_user_for_index_selection(range);

  if(result < 1 || static_cast<size_t>(result) > equippable_indices.size()) {
    std::cout << color(ColorType::RED) << "Invalid selection."
              << color(ColorType::DEFAULT) << std::endl;
    return;
  }

  size_t inventory_index = equippable_indices[static_cast<size_t>(result - 1)];

  const auto &selected_stack = items[inventory_index];
  std::string item_name      = selected_stack.item->get_name();
  auto        location =
      CoreUtils::to_equipment_location(selected_stack.item->get_type());

  if(!location) {
    std::cout << color(ColorType::RED) << "Item cannot be equipped."
              << color(ColorType::DEFAULT) << std::endl;
    return;
  }

  auto item_to_equip = m_player->m_inventory->extract_item(inventory_index);

  if(!item_to_equip) {
    std::cout << color(ColorType::RED) << "Failed to retrieve item."
              << color(ColorType::DEFAULT) << std::endl;
    return;
  }

  m_player->m_stats->compute_stats_from_item(item_to_equip->get_stats());

  auto unequipped_item =
      m_player->m_equipment->equip_item(*location, std::move(item_to_equip));

  if(unequipped_item) {
    m_player->m_stats->remove_stats_from_item(unequipped_item->get_stats());
    m_player->m_inventory->add_item(std::move(unequipped_item));
    std::cout << color(ColorType::YELLOW)
              << "Replaced previously equipped item."
              << color(ColorType::DEFAULT) << std::endl;
  }

  std::cout << color(ColorType::GREEN) << "Equipped: " << item_name
            << color(ColorType::DEFAULT) << std::endl;

  const auto &stats = m_player->m_stats->get_stats();

  std::cout << "New stats:\nHealth: " << stats.health
            << "\nAttack: " << stats.attack << "\n";

  getchar();
}

void InventoryStatsMenu::unequip_item()
{
  getchar();
}

void InventoryStatsMenu::use_item()
{
  getchar();
}

void InventoryStatsMenu::throw_item()
{
  getchar();
}
