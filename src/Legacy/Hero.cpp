#include "Hero.h"
#include "CoreUtils.h"
#include "ItemRegistry/ItemRegistry.h"
#include "SystemRelated.h"
#include "Utils/DrawUtils.h"
#include "god.h"

#include <iostream>

Hero::Hero(const std::string &name)
    : m_name(std::move(name)),
      m_stats(std::make_unique<Stats>()),
      m_equipment(std::make_unique<Equipment>()),
      m_inventory(std::make_unique<Inventory>())
{
}

int Hero::get_golds() const
{
  return m_gold;
}

std::string Hero::get_name()
{
  return m_name;
}

void Hero::give_gold(int quantity)
{
  m_gold += quantity;
}

int Hero::combat_main()
{
  Utils::clear_screen();

  std::string method_select;
  auto       *monster = generate_monster(this);

  bool        fight = true;
  while(monster->get_hp() > 0 && m_stats->get_stats().health > 0) {
    std::string choice = "0";
    while(choice != "1" && choice != "2" && choice != "3") {
      std::cout << "[COMBAT]" << std::endl;
      std::cout << std::endl;
      std::cout << monster->get_name() << " :" << std::endl;
      std::cout << "| Hp: " << monster->get_hp() << " / "
                << monster->get_max_hp() << std::endl;
      std::cout << "| Attack: " << monster->get_atk() << std::endl;
      std::cout << std::endl << std::endl;
      std::cout << get_name() << " :" << std::endl;
      std::cout << "| Hp: " << m_stats->get_stats().health << " / "
                << m_stats->get_stats().max_health << std::endl;
      std::cout << "| Attack: " << m_stats->get_stats().attack << std::endl;
      std::cout << std::endl << std::endl << std::endl;
      std::cout << "What do you want to do ?" << std::endl;
      std::cout << "[1] Attack" << std::endl;
      std::cout << "[2] Use an item" << std::endl;
      std::cout << "[3] Run (10% chance)" << std::endl;
      std::cout << ">";
      std::getline(std::cin, choice);
      Utils::clear_screen();
    }
    if(choice == "1") {
      monster->take_dmg(this);
    } else if(choice == "2") {
      /*show_useable_items();*/
    } else if(choice == "3") {
      m_stats->take_damage(monster->get_atk());

      if(generate_random_number(0, 100) <= 10) {
        fight = false;
        break;
      }
    }
  }

  Utils::clear_screen();
  if(fight) {
    if(monster->get_hp() <= 0) {
      std::cout << color(ColorType::BLUE) << "[VICTORY]"
                << color(ColorType::DEFAULT) << std::endl;
      std::cout << "[DROPS]" << std::endl;
      std::cout << "You've got:" << std::endl;
      monster->drop(this);
      int will_drop = generate_random_number(0, 100);
      if(will_drop <= 30) {
        std::vector<std::string> killing_sentences = {
            "cutting in half", "ripping off", "dismembering"
        };
        std::cout << std::endl << std::endl;
        std::cout << "While you were "
                  << killing_sentences[static_cast<size_t>(
                         generate_random_number(0, 2)
                     )]
                  << " your enemy, you saw a chest.." << std::endl
                  << "You opened it and found:";

        std::unique_ptr<GearInstance> gear_instance =
            ItemRegistry::get().generate_random_item(m_stats->get_stats().level
            );

        const auto &item_gear_instance = gear_instance->get_item();

        std::cout
            << color(get_color_from_string(get_color_from_rarity(
                   CoreUtils::rarity_to_string(item_gear_instance->get_rarity())
               )))
            << item_gear_instance->get_name() << color(ColorType::DEFAULT);

        m_inventory->add_item(std::move(gear_instance), 1);
        std::cout << std::endl << std::endl;
        std::cout << "Press enter to continue. . .";
        getchar();
        Utils::clear_screen();
      }

      int levels_gained = m_stats->level_up();

      if(levels_gained > 0) {
        std::cout << "Level + 1\n";
        getchar();
      }
    } else {
      std::cout << color(ColorType::RED) << "[DEFEAT]"
                << color(ColorType::DEFAULT) << std::endl;
      std::cout << "Press enter to exit. . ." << std::endl;
      getchar();
      exit(BYE_THANKS_4_PLAY);
    }
  }
  Utils::clear_screen();
  return 0;
}

int Hero::get_status_rate()
{
  return m_status_rate;
}
