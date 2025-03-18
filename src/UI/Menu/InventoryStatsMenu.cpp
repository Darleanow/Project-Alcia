#include "InventoryStatsMenu.h"
#include "CoreUtils.h"
#include "UISystem.h"
#include "Utils/DrawUtils.h"
#include "Item.h"

#include <iostream>
#include <stdexcept>

InventoryStatsMenu::InventoryStatsMenu(const std::shared_ptr<Hero> &player)
    : AMenu(player)
{
  initialize_actions();
}

void InventoryStatsMenu::initialize_actions()
{
  actions_ = {
      {1, [this] { equip_item(); }  },
      {2, [this] { unequip_item(); }},
      {3, [this] { use_item(); }    },
      {4, [this] { throw_item(); }  },
      {5, [] {}                     }
  };
}

void InventoryStatsMenu::execute()
{
  Utils::clear_screen();
  draw_gui();
  std::cout << "\n\n";
  show_actions();

  UISystem ui_system;
  Range    range {1, actions_.size()};
  int      selection = ui_system.prompt_user_for_index_selection(range);

  handle_user_selection(selection);
}

void InventoryStatsMenu::handle_user_selection(int selection)
{
  if(actions_.find(selection) != actions_.end()) {
    actions_[selection]();
  } else {
    throw std::runtime_error("Unknown action selection.");
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

void InventoryStatsMenu::equip_item()
{
  Utils::clear_screen();
  std::vector<size_t> equippable_indices;
  show_equippable_items(equippable_indices);

  if(equippable_indices.empty()) {
    std::cout << color(ColorType::RED) << "No items available for equipping.\n"
              << color(ColorType::DEFAULT) << "Press enter to continue...";
    getchar();
    return;
  }

  UISystem ui_system;
  Range    range {1, equippable_indices.size()};
  int      selection = ui_system.prompt_user_for_index_selection(range) - 1;

  size_t   inventory_index = equippable_indices[static_cast<size_t>(selection)];
  auto     item_to_equip = m_player->m_inventory->extract_item(inventory_index);

  if(!item_to_equip)
    return;

  auto location = CoreUtils::to_equipment_location(item_to_equip->get_type());
  if(!location)
    return;

  m_player->m_stats->compute_stats_from_item(item_to_equip->get_stats());

  auto unequipped_item =
      m_player->m_equipment->equip_item(*location, std::move(item_to_equip));

  if(unequipped_item) {
    m_player->m_stats->remove_stats_from_item(unequipped_item->get_stats());
    m_player->m_inventory->add_item(std::move(unequipped_item));
  }
}

void InventoryStatsMenu::unequip_item()
{
  Utils::clear_screen();
  std::vector<EquipmentLocation> equipped_locations;
  show_equipped_items(equipped_locations);

  if(equipped_locations.empty()) {
    std::cout << color(ColorType::RED) << "No equipment available to unequip."
              << color(ColorType::DEFAULT) << "\nPress enter to continue...";
    getchar();
    return;
  }

  UISystem ui_system;
  Range    range {1, equipped_locations.size()};
  int      selection = ui_system.prompt_user_for_index_selection(range) - 1;

  auto     item = m_player->m_equipment->unequip_item(
      equipped_locations[static_cast<size_t>(selection)]
  );

  if(item) {
    m_player->m_stats->remove_stats_from_item(item->get_stats());
    m_player->m_inventory->add_item(std::move(item));
  }

  std::cout << color(ColorType::GREEN) << "\nSuccessfully unequipped item!\n"
            << color(ColorType::DEFAULT) << "Press enter to continue...";
  getchar();
}

void InventoryStatsMenu::use_item()
{
  Utils::clear_screen();
  std::vector<size_t> useable_items_indices;
  show_useable_items(useable_items_indices);

  if(useable_items_indices.empty()) {
    std::cout << color(ColorType::RED) << "No item to use."
              << color(ColorType::DEFAULT) << "\nPress enter to continue...";

    getchar();
    return;
  }

  UISystem ui_system;
  Range    range {1, useable_items_indices.size()};
  int      selection = ui_system.prompt_user_for_index_selection(range) - 1;

  auto     item = m_player->m_inventory->extract_item(
      useable_items_indices[static_cast<size_t>(selection)]
  );

  m_player->m_stats->add_stats(item->get_stats());
}

void InventoryStatsMenu::throw_item()
{
  Utils::clear_screen();
  size_t index = 0;

  std::cout << "[" << color(ColorType::BLUE) << "Throw an item"
            << color(ColorType::DEFAULT) << "]\n\n";

  for(index = 0; index < m_player->m_inventory->get_items().size(); ++index) {
    const auto &item_stack = m_player->m_inventory->get_items()[index];
    std::cout << "[" << index + 1 << "] "
              << color(get_color_from_string(
                     get_color_from_rarity(item_stack.item->get_rarity())
                 ))
              << item_stack.item->get_name() << color(ColorType::DEFAULT)
              << " x " << item_stack.quantity << '\n';
  }

  std::cout << "\nSelect an item\n";

  UISystem    ui_system;
  Range       range {1, index + 1};
  const auto  selection = ui_system.prompt_user_for_index_selection(range) - 1;

  const auto &selected_item =
      m_player->m_inventory->get_items()[static_cast<size_t>(selection)];
  const auto &item_name = selected_item.item->get_name();

  std::cout << "\nSelect a quantity (0 - " << selected_item.quantity << ")\n";

  Range      scd_range {0, static_cast<size_t>(selected_item.quantity)};
  const auto quantity_selection =
      ui_system.prompt_user_for_index_selection(scd_range);

  m_player->m_inventory->remove_item(
      static_cast<size_t>(selection), quantity_selection
  );

  std::cout << color(ColorType::GREEN) << "Successfully"
            << color(ColorType::DEFAULT) << " removed " << quantity_selection
            << " " << item_name << (quantity_selection > 1 ? "s" : "")
            << "\nPress enter to continue...";
  getchar();
}

void InventoryStatsMenu::show_equippable_items(std::vector<size_t> &indices
) const
{
  size_t display_index = 1;
  for(size_t i = 0; i < m_player->m_inventory->get_items().size(); ++i) {
    const auto &item = m_player->m_inventory->get_items()[i].item;
    if(CoreUtils::to_equipment_location(item->get_type())) {
      std::cout << '[' << display_index++ << "] "
                << color(get_color_from_string(
                       get_color_from_rarity(item->get_rarity())
                   ))
                << item->get_name() << color(ColorType::DEFAULT) << '\n';
      indices.push_back(i);
    }
  }
}

void InventoryStatsMenu::show_useable_items(std::vector<size_t> &indices) const
{
  size_t display_index = 1;
  for(size_t i = 0; i < m_player->m_inventory->get_items().size(); ++i) {
    const auto &item = m_player->m_inventory->get_items()[i].item;
    if(item->get_type() == "Potion") {
      std::cout << '[' << display_index++ << "] "
                << color(get_color_from_string(
                       get_color_from_rarity(item->get_rarity())
                   ))
                << item->get_name() << color(ColorType::DEFAULT) << '\n';
      indices.push_back(i);
    }
  }
}

void InventoryStatsMenu::show_equipped_items(
    std::vector<EquipmentLocation> &locations
) const
{
  size_t index = 1;
  for(const auto location : EquipmentLocationList) {
    const auto &item = m_player->m_equipment->get_item(location);
    if(item) {
      std::cout << '[' << index++ << "] "
                << color(get_color_from_string(
                       get_color_from_rarity(item->get_rarity())
                   ))
                << item->get_name() << color(ColorType::DEFAULT) << '\n';
      locations.push_back(location);
    }
  }
}
