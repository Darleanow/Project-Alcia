#include "Hero.h"
#include "Item.h"
#include "UI/SystemRelated.h"
#include "UI/Utils/DrawUtils.h"
#include "god.h"

#include <iostream>
#include <unordered_map>

Hero::Hero(const std::string &name) : m_name(std::move(name)) {}

int Hero::get_hp()
{
  return m_hp;
}

int Hero::get_golds() const
{
  return m_gold;
}

int Hero::get_max_hp()
{
  return m_max_hp;
}

void Hero::set_hp(int quantity)
{
  m_hp += quantity;
}

std::string Hero::get_name()
{
  return m_name;
}

void Hero::take_dmg(int quantity)
{
  m_hp -= quantity;
}

void Hero::give_gold(int quantity)
{
  m_gold += quantity;
}

const std::vector<std::pair<Item *, int>> Hero::get_inventory() const
{
  return m_inventory;
}

void Hero::give(Item *item, int amount)
{
  bool found = false;
  for(size_t search = 0; search < m_inventory.size(); search++) {
    if(m_inventory[search].first->get_name() == item->get_name()) {
      m_inventory.at(search).second += amount;
      found = true;
      break;
    }
  }
  if(!found) {
    m_inventory.push_back(std::make_pair(item, 1));
  }
}

int Hero::get_level()
{
  return m_level;
}

int Hero::combat_main()
{
  Utils::clear_screen();

  std::string method_select;
  auto       *monster = generate_monster(this);

  bool        fight = true;
  while(monster->get_hp() > 0 && get_hp() > 0) {
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
      std::cout << "| Hp: " << get_hp() << " / " << get_max_hp() << std::endl;
      std::cout << "| Attack: " << get_atk() << std::endl;
      std::cout << std::endl << std::endl << std::endl;
      std::cout << "What do you want to do ?" << std::endl;
      std::cout << "1.Attack" << std::endl;
      std::cout << "2.Use an item" << std::endl;
      std::cout << "3.Run (10% chance)" << std::endl;
      std::cout << "Choice: ";
      std::getline(std::cin, choice);
      Utils::clear_screen();
    }
    if(choice == "1") {
      monster->take_dmg(this);
    } else if(choice == "2") {
      show_useable_items();
    } else if(choice == "3") {
      take_dmg(monster->get_atk());
      if(generate_random_number(0, 100) <= 10) {
        fight = false;
        break;
      }
    }
  }

  Utils::clear_screen();
  if(fight) {
    if(monster->get_hp() <= 0) {
      m_atk -= 15 * m_strength_potions_used;
      m_strength_potions_used = 0;

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
        auto item = generate_item();
        std::cout << color(get_color_from_string(
                         get_color_from_rarity(item->get_rarity())
                     ))
                  << item->get_name() << color(ColorType::DEFAULT);
        if(check(item->get_name())) {
          add(item->get_name(), 1);
        } else {
          give(item);
        }
        std::cout << std::endl << std::endl;
        std::cout << "Press enter to continue. . .";
        getchar();
        Utils::clear_screen();
      }

      if(compute_xp_needed() == 0) {
        level_up();
        m_xp_to_levelup = get_xp_to_lvl();
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

void Hero::remove_elem(size_t index, int amount)
{
  if(amount > 0) {
    int rest = m_inventory[index].second;
    rest -= amount;
    m_inventory[index].second = rest;
    if(m_inventory[index].second <= 0) {
      m_inventory.erase(m_inventory.begin() + static_cast<long>(index));
    }
  }
}

void Hero::rem_by_name(std::string name, int quantity)
{
  for(size_t i = 0; i < m_inventory.size(); i++) {
    if(m_inventory[i].first->get_name() == name) {
      remove_elem(i, quantity);
    }
  }
}

void Hero::delete_an_item()
{
  Utils::clear_screen();

  std::string quantity_to_delete;
  std::string delete_choice;
  while(delete_choice < "1" ||
        static_cast<size_t>(delete_choice[0] - 49) >= m_inventory.size()) {
    show_inventory();
    std::cout << "Choose an element you want to delete (the number left to the "
                 "item name) or 'quit' to quit: ";
    std::getline(std::cin, delete_choice);

    if(delete_choice == "quit") {
      break;
    }
    if(static_cast<size_t>(delete_choice[0] - 49) < m_inventory.size()) {
      std::cout << std::endl;
      std::cout << "Enter amount to delete or 'cancel' to cancel: ";
      std::cin >> quantity_to_delete;
      if(quantity_to_delete != "cancel") {
        remove_elem(
            static_cast<size_t>(delete_choice[0] - 49), stoi(quantity_to_delete)
        );
      }
    }
    Utils::clear_screen();
  }
}

void Hero::equip(Item *item)
{
  if(item->get_type() == ItemLocationEquipType::PrimaryHand) {
    if(!(m_right_hand.empty())) {
      give(m_right_hand[0]);
      m_right_hand.clear();
    }
    m_right_hand.push_back(item);
    m_atk += item->get_atk();
  } else if(item->get_type() == ItemLocationEquipType::Helmet) {
    if(!(m_helmet.empty())) {
      give(m_helmet[0]);
      m_helmet.clear();
    }
    m_helmet.push_back(item);
    m_max_hp += item->get_hp();
    m_hp += item->get_hp();
  } else if(item->get_type() == ItemLocationEquipType::Chestplate) {
    if(!(m_chestplate.empty())) {
      give(m_chestplate[0]);
      m_chestplate.clear();
    }
    m_chestplate.push_back(item);
    m_max_hp += item->get_hp();
    m_hp += item->get_hp();
  } else if(item->get_type() == ItemLocationEquipType::Leggings) {
    if(!(m_pants.empty())) {
      give(m_pants[0]);
      m_pants.clear();
    }
    m_pants.push_back(item);
    m_max_hp += item->get_hp();
    m_hp += item->get_hp();
  } else if(item->get_type() == ItemLocationEquipType::Boots) {
    if((!m_boots.empty())) {
      give(m_boots[0]);
      m_boots.clear();
    }
    m_boots.push_back(item);
    m_max_hp += item->get_hp();
    m_hp += item->get_hp();
  }
  remove_from_inventory(item);
}

void Hero::unequip(int choice)
{
  if(choice == 1) {
    if(m_right_hand.empty()) {
      return;
    }

    give(m_right_hand[0]);
    m_atk -= m_right_hand[0]->get_atk();
    m_right_hand.clear();

  } else if(choice == 2) {
    if(m_helmet.empty()) {
      return;
    }

    give(m_helmet[0]);
    m_max_hp -= m_helmet[0]->get_hp();
    m_hp -= m_helmet[0]->get_hp();
    m_helmet.clear();

  } else if(choice == 3) {
    if(m_chestplate.empty()) {
      return;
    }

    give(m_chestplate[0]);
    m_max_hp -= m_chestplate[0]->get_hp();
    m_hp -= m_chestplate[0]->get_hp();
    m_chestplate.clear();

  } else if(choice == 4) {
    if(m_pants.empty()) {
      return;
    }

    give(m_pants[0]);
    m_max_hp -= m_pants[0]->get_hp();
    m_hp -= m_pants[0]->get_hp();
    m_pants.clear();

  } else if(choice == 5) {
    if(m_boots.empty()) {
      return;
    }

    give(m_boots[0]);
    m_max_hp -= m_boots[0]->get_hp();
    m_hp -= m_boots[0]->get_hp();
    m_boots.clear();
  }
}

void Hero::remove_from_inventory(Item *item)
{
  for(size_t search = 0; search < m_inventory.size(); search++) {
    if(m_inventory[search].first->get_name() == item->get_name()) {
      remove_elem(search, 1);
      break;
    }
  }
}

void Hero::show_inventory()
{
  std::cout << "[INVENTORY]" << std::endl;
  for(size_t items = 0; items < m_inventory.size(); items++) {
    std::cout << items + 1 << ". "
              << color(get_color_from_string(get_color_from_rarity(
                     m_inventory[items].first->get_rarity()
                 )))
              << m_inventory[items].first->get_name()
              << color(ColorType::DEFAULT) << " | " << m_inventory[items].second
              << std::endl;
  }
  if(m_inventory.size() == 0) {
    std::cout << "  [EMPTY]";
  }
  std::cout << std::endl;
}

bool Hero::check(std::string name)
{
  for(size_t i = 0; i < m_inventory.size(); i++) {
    if(m_inventory[i].first->get_name() == name) {
      return true;
    }
  }
  return false;
}

int Hero::check_quant(std::string item_name)
{
  for(size_t i = 0; i < m_inventory.size(); i++) {
    if(m_inventory[i].first->get_name() == item_name) {
      return m_inventory[i].second;
    }
  }
  return 0;
}

void Hero::add(std::string name, int amount)
{
  for(size_t i = 0; i < m_inventory.size(); i++) {
    if(m_inventory[i].first->get_name() == name) {
      m_inventory[i].second += amount;
      break;
    }
  }
}

void Hero::show_useable_items()
{
  std::vector<std::pair<Item *, int>> potions;
  for(size_t i = 0; i < m_inventory.size(); i++) {
    if(m_inventory[i].first->get_type() == ItemLocationEquipType::Potion) {
      potions.push_back(m_inventory[i]);
    }
  }
  if(potions.size() < 1) {
    std::cout << "No items to use." << std::endl;
    std::cout << "Press enter to continue. . .";
    getchar();
    Utils::clear_screen();
  } else {
    std::string choice = "0";
    while(choice == "0" &&
          (static_cast<size_t>(choice[0] - 49) > potions.size())) {
      std::cout << "[USEABLES]" << std::endl;
      for(size_t i = 0; i < potions.size(); i++) {
        std::cout << i + 1 << ". "
                  << color(get_color_from_string(
                         get_color_from_rarity(potions[i].first->get_rarity())
                     ))
                  << potions[i].first->get_name() << color(ColorType::DEFAULT)
                  << " x " << potions[i].second << std::endl;
      }
      std::cout << std::endl << std::endl;
      std::cout << "Enter quit/exit to cancel." << std::endl;
      std::cout << "Your choice: ";
      std::getline(std::cin, choice);
      if((static_cast<size_t>(choice[0] - 49) <= potions.size() &&
          static_cast<size_t>(choice[0] - 49) >= 0) ||
         choice == "quit" || choice == "exit") {
        if(choice != "quit" && choice != "exit") {
          if(potions[static_cast<size_t>(choice[0] - 49)].first->get_name() ==
             "Health Potion") {
            m_hp +=
                potions[static_cast<size_t>(choice[0] - 49)].first->get_hp();
            m_hp = std::min(m_hp, m_max_hp);
            remove_from_inventory(
                potions[static_cast<size_t>(choice[0] - 49)].first
            );
            Utils::clear_screen();
          } else if(potions[static_cast<size_t>(choice[0] - 49)]
                        .first->get_name() == "Strength Potion") {
            m_atk +=
                potions[static_cast<size_t>(choice[0] - 49)].first->get_atk();
            m_strength_potions_used += 1;
          }
        }
        break;
      }
      Utils::clear_screen();
    }
  }
}

void Hero::show_Town_actions()
{
  int town_choice = 0;
  while(!(town_choice == 1 || town_choice == 2 || town_choice == 3)) {
    std::cout << "[TOWN]" << std::endl;
    std::cout << "1. Go into the Forge" << std::endl;
    std::cout << "2. Go into the Shop" << std::endl;
    std::cout << "3. Leave town" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> town_choice;
  }

  Utils::clear_screen();

  if(town_choice == 1) {
    show_black_smith_actions();
  } else if(town_choice == 2) {
    show_shop_options();
  } else {
  }
}

void Hero::show_black_smith_actions()
{
  std::vector<std::string> item_names {
      "Common Sword",       "Rare Sword",         "Epic Sword",
      "Legendary Sword",    "Common m_helmet",    "Rare m_helmet",
      "Epic m_helmet",      "Legendary m_helmet", "Common m_chestplate",
      "Rare m_chestplate",  "Epic m_chestplate",  "Legendary m_chestplate",
      "Common Leggings",    "Rare Leggings",      "Epic Leggings",
      "Legendary Leggings", "Common m_boots",     "Rare Boots",
      "Epic m_boots",       "Legendary Boots",
  };

  ZombieFlesh                                  flesh;
  ZombieEye                                    eye;
  BoneShard                                    shards;
  Bones                                        bones;
  TrollBelt                                    belt;
  TrollFinger                                  finger;
  EmptySack                                    sack;
  KoboldScepter                                scepter;
  KoboldTails                                  tails;
  OreadePowder                                 powder;
  MagicFragments                               fragments;
  DragonScale                                  scale;
  DragonTooth                                  tooth;

  std::vector<std::unordered_map<Item *, int>> recipes {
      {{&flesh, 10}, {&eye, 4}},
      {{&flesh, 20}, {&eye, 10}},
      {{&belt, 2}, {&sack, 4}, {&bones, 15}},
      {{&scepter, 15},
       {&tooth, 3},
       {&finger, 25},
       {&fragments, 40},
       {&bones, 100}},
      {{&shards, 5}, {&bones, 10}},
      {{&shards, 18}, {&bones, 15}},
      {{&shards, 35}, {&bones, 24}, {&sack, 2}},
      {{&powder, 12}, {&fragments, 4}, {&scale, 2}, {&bones, 67}},
      {{&shards, 15}, {&bones, 21}},
      {{&shards, 24}, {&bones, 21}},
      {{&tails, 4}, {&fragments, 2}, {&scale, 3}, {&sack, 10}},
      {{&powder, 19}, {&tooth, 3}, {&scale, 6}, {&bones, 95}},
      {{&shards, 8}, {&bones, 14}},
      {{&shards, 21}, {&bones, 19}},
      {{&tails, 2}, {&tooth, 1}, {&scale, 1}, {&sack, 8}},
      {{&powder, 14}, {&tooth, 6}, {&scale, 5}, {&bones, 84}},
      {{&shards, 4}, {&flesh, 10}},
      {{&shards, 7}, {&flesh, 18}},
      {{&finger, 12}, {&powder, 8}, {&sack, 14}},
      {{&powder, 12}, {&finger, 4}, {&scale, 2}, {&bones, 54}},
  };

  std::string user_input;
  while(user_input != "quit") {
    std::cout << "[FORGE]" << std::endl;
    std::cout << "Welcome to the forge !" << std::endl << std::endl;

    std::cout << "[ITEM LIST]" << std::endl;
    for(size_t i = 0; i < item_names.size(); i++) {
      std::cout << i + 1 << ". "
                << (!(item_names[i].find("Legendary"))
                        ? color(ColorType::YELLOW)
                    : !(item_names[i].find("Epic")) ? color(ColorType::RED)
                    : !(item_names[i].find("Rare")) ? color(ColorType::BLUE)
                                                    : color(ColorType::GREEN))
                << item_names[i] << color(ColorType::DEFAULT) << "  ";
      if(!item_names[i].find("Legendary")) {
        std::cout << std::endl;
      }
    }
    std::cout << std::endl << std::endl;
    std::cout << "Enter item number to view needed resources / craft it or "
                 "'quit' to exit"
              << std::endl;
    std::cout << "Choice: ";
    std::cin >> user_input;
    if(user_input == "quit" or !is_digits(user_input)) {
      break;
    } else if(static_cast<size_t>(std::stoi(user_input) - 1) <
                  item_names.size() &&
              std::stoi(user_input) - 1 >= 0) {
      std::string choice;
      while(choice != "1" && choice != "2") {
        Utils::clear_screen();

        size_t index = static_cast<size_t>(std::stoi(user_input));

        std::cout << "[DETAILS]" << std::endl;
        std::cout << "["
                  << (!(item_names[index - 1].find("Legendary"))
                          ? color(ColorType::YELLOW)
                      : !(item_names[index - 1].find("Epic"))
                          ? color(ColorType::RED)
                      : !(item_names[index - 1].find("Rare"))
                          ? color(ColorType::BLUE)
                          : color(ColorType::GREEN))
                  << item_names[index - 1] << color(ColorType::DEFAULT) << "]"
                  << std::endl
                  << std::endl;
        std::cout << "Needed items: " << std::endl;
        for(auto item : recipes[index - 1]) {
          std::cout << "- "
                    << color(get_color_from_string(
                           get_color_from_rarity(item.first->get_rarity())
                       ))
                    << item.first->get_name() << color(ColorType::DEFAULT)
                    << " x " << item.second;
          std::cout << " || "
                    << "You have : " << check_quant(item.first->get_name())
                    << std::endl;
        }

        std::cout << std::endl;
        std::cout << "What do you want to do ?" << std::endl;
        std::cout << "1. Craft the item" << std::endl;
        std::cout << "2. Go back" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
        if(choice == "2") {
          Utils::clear_screen();
          break;
        } else if(choice == "1") {
          bool enough = true;
          for(auto item : recipes[index - 1]) {
            if(!(check_quant(item.first->get_name()) >= item.second)) {
              enough = false;
              std::cout << "Not enough materials. . ." << std::endl;
              std::cout << "Press enter to continue. . .";
              getchar();
              Utils::clear_screen();
              break;
            }
          }
          if(enough == true) {
            std::cout << "Successfully made the " << item_names[index - 1]
                      << std::endl;
            for(auto item : recipes[index - 1]) {
              rem_by_name(item.first->get_name(), item.second);
            }
            if(item_names[index - 1] == "Common Sword")
              give(new CommonSword);
            else if(item_names[index - 1] == "Rare Sword")
              give(new RareSword);
            else if(item_names[index - 1] == "Epic Sword")
              give(new EpicSword);
            else if(item_names[index - 1] == "Legendary Sword")
              give(new LegendarySword);
            else if(item_names[index - 1] == "Common Helmet")
              give(new CommonHelmet);
            else if(item_names[index - 1] == "Rare Helmet")
              give(new RareHelmet);
            else if(item_names[index - 1] == "Epic Helmet")
              give(new EpicHelmet);
            else if(item_names[index - 1] == "Legendary Helmet")
              give(new LegendaryHelmet);
            else if(item_names[index - 1] == "Common Chestplate")
              give(new CommonChestplate);
            else if(item_names[index - 1] == "Rare Chestplate")
              give(new RareChestplate);
            else if(item_names[index - 1] == "Epic Chestplate")
              give(new EpicChestplate);
            else if(item_names[index - 1] == "Legendary Chestplate")
              give(new LegendaryChestplate);
            else if(item_names[index - 1] == "Common Leggings")
              give(new CommonLeggings);
            else if(item_names[index - 1] == "Rare Leggings")
              give(new RareLeggings);
            else if(item_names[index - 1] == "Epic Leggings")
              give(new EpicLeggings);
            else if(item_names[index - 1] == "Legendary Leggings")
              give(new LegendaryLeggings);
            else if(item_names[index - 1] == "Common m_boots")
              give(new CommonBoots);
            else if(item_names[index - 1] == "Rare m_boots")
              give(new RareBoots);
            else if(item_names[index - 1] == "Epic m_boots")
              give(new EpicBoots);
            else if(item_names[index - 1] == "Legendary m_boots")
              give(new LegendaryBoots);
            std::cout << std::endl << "Press Enter to continue. . .";
            getchar();
            Utils::clear_screen();
          }
        }
      }
    }
  }
}

void Hero::show_shop_options()
{

  std::string sel_choice;
  while(sel_choice != "1" && sel_choice != "2" && sel_choice != "3") {
    std::cout << "Welcome to the shop !" << std::endl;
    std::cout << "1. Buy Items" << std::endl;
    std::cout << "2. Sell Items" << std::endl;
    std::cout << "3. Leave shop" << std::endl;
    std::cout << std::endl << "Choice: ";
    std::cin >> sel_choice;
    Utils::clear_screen();
  }
  if(sel_choice == "1") {
    std::vector<Item *> purchaseable_items = {
        new CommonSword,         new CommonLeggings,   new CommonHelmet,
        new CommonBoots,         new CommonChestplate, new RareBoots,
        new RareChestplate,      new RareHelmet,       new RareLeggings,
        new RareSword,           new HealthPotion,     new StrengthPotion,
        new EpicSword,           new EpicBoots,        new EpicChestplate,
        new EpicHelmet,          new EpicLeggings,     new LegendaryBoots,
        new LegendaryChestplate, new LegendaryHelmet,  new LegendaryLeggings,
        new LegendarySword
    };
    std::vector<size_t> odds = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        2,
        static_cast<size_t>(m_level > 40 ? 1 : 0.01),
        static_cast<size_t>(m_level > 40 ? 1 : 0.001),
        static_cast<size_t>(m_level > 40 ? 1 : 0.001),
        static_cast<size_t>(m_level > 40 ? 1 : 0.001),
        static_cast<size_t>(m_level > 40 ? 1 : 0.001),
        static_cast<size_t>(m_level > 40 ? 1 : 0.001),

        static_cast<size_t>(m_level > 50 ? 0.1 : 0.0001),
        static_cast<size_t>(m_level > 50 ? 0.1 : 0.0001),
        static_cast<size_t>(m_level > 50 ? 0.1 : 0.0001),
        static_cast<size_t>(m_level > 50 ? 0.1 : 0.0001),
        static_cast<size_t>(m_level > 50 ? 0.1 : 0.0001),

    };
    std::vector<Item *> items = {random_item(purchaseable_items, odds),
                                 random_item(purchaseable_items, odds),
                                 random_item(purchaseable_items, odds),
                                 random_item(purchaseable_items, odds),
                                 random_item(purchaseable_items, odds),
                                 random_item(purchaseable_items, odds)};
    Utils::clear_screen();
    std::cout << "[BUY]" << std::endl;
    for(size_t i = 0; i < items.size(); i++) {
      std::cout << "" << i + 1 << ". "
                << color(get_color_from_string(
                       get_color_from_rarity(items[i]->get_rarity())
                   ))
                << items[i]->get_name() << color(ColorType::DEFAULT)
                << "  Price: " << items[i]->get_price() << " golds"
                << std::endl;
    }
    std::cout << std::endl << std::endl;
    std::string choice;
    while(choice != "1" && choice != "2" && choice != "3" && choice != "4" &&
          choice != "5" && choice != "6" && choice != "exit" &&
          choice != "Exit" && choice != "quit" && choice != "Quit") {
      std::cout << "Enter item's number to purchase it, enter 'quit' to leave "
                   "the shop"
                << std::endl;
      std::cout << std::endl;
      std::cout << "You have " << m_gold << " gold." << std::endl;
      std::cout << "Your choice:";
      std::cin >> choice;
      std::cout << std::endl;
      if(choice == "exit" || choice == "Exit" || choice == "quit" ||
         choice == "Quit") {
        Utils::clear_screen();
        show_shop_options();
      }
      if(choice == "1" || choice == "2" || choice == "3" || choice == "4" ||
         choice == "5" || choice == "6") {
        if(items[static_cast<size_t>(choice[0]) - 49]->get_price() > m_gold) {
          std::cout << "You're too poor to buy this :(" << std::endl;
          std::cout << "You can leave the shop or try again but it wont work !"
                    << std::endl;
          std::cout << "Press enter to continue. . .";
          getchar();
          Utils::clear_screen();
          show_shop_options();
        } else {
          m_gold -= items[static_cast<size_t>(choice[0]) - 49]->get_price();
          if(check(items[static_cast<size_t>(choice[0]) - 49]->get_name())) {
            add(items[static_cast<size_t>(choice[0]) - 49]->get_name(), 1);
          }
          give(items[static_cast<size_t>(choice[0]) - 49]);
          std::cout << "Successfully bought the item !" << std::endl;
          std::cout << "Press enter to continue. . .";
          getchar();
          Utils::clear_screen();
          show_shop_options();
        }
      }
    }
  } else if(sel_choice == "2") {
    std::string choice;
    if(!m_inventory.empty()) {
      while(choice != "quit" || !m_inventory.empty()) {
        std::cout << "[SELL]" << std::endl;
        std::cout << "You have " << m_gold << " golds." << std::endl;
        std::cout << "---------------------------------------------"
                  << std::endl;
        for(size_t i = 0; i < m_inventory.size(); i++) {
          std::cout << i + 1 << ". "
                    << color(get_color_from_string(get_color_from_rarity(
                           m_inventory[i].first->get_rarity()
                       )))
                    << m_inventory[i].first->get_name()
                    << color(ColorType::DEFAULT) << " x "
                    << m_inventory[i].second << " || "
                    << m_inventory[i].first->get_price() << " golds."
                    << std::endl;
        }
        std::cout << std::endl
                  << std::endl
                  << "Enter item number, or 'quit' to go back" << std::endl;
        std::cout << std::endl << "Choice: ";
        std::cin >> choice;
        if(choice == "quit" || m_inventory.empty()) {
          break;
        } else if(static_cast<size_t>(choice[0] - 49) < m_inventory.size() &&
                  static_cast<size_t>(choice[0] - 49) >= 0) {
          std::cout << "[SELECTED] -> "
                    << color(get_color_from_string(get_color_from_rarity(
                           m_inventory[static_cast<size_t>(choice[0] - 49)]
                               .first->get_rarity()
                       )))
                    << m_inventory[static_cast<size_t>(choice[0] - 49)]
                           .first->get_name()
                    << color(ColorType::DEFAULT) << std::endl;
          std::cout << std::endl
                    << "Enter quantity or '0' to cancel" << std::endl;
          std::string quant;
          std::cout << "Choice: ";
          std::cin >> quant;
          if(quant != "0") {
            if(static_cast<int>(quant[0]) >
               m_inventory[static_cast<size_t>(choice[0] - 49)].second) {
              std::cout
                  << std::endl
                  << "Sold "
                  << m_inventory[static_cast<size_t>(choice[0] - 49)].second
                  << " of "
                  << m_inventory[static_cast<size_t>(choice[0] - 49)]
                         .first->get_name()
                  << " for "
                  << m_inventory[static_cast<size_t>(choice[0] - 49)]
                             .first->get_price() *
                         m_inventory[static_cast<size_t>(choice[0] - 49)].second
                  << " golds" << std::endl;
              m_gold += m_inventory[static_cast<size_t>(choice[0] - 49)]
                            .first->get_price() *
                        m_inventory[static_cast<size_t>(choice[0] - 49)].second;
              remove_elem(
                  static_cast<size_t>(choice[0] - 49),
                  m_inventory[static_cast<size_t>(choice[0] - 49)].second
              );
            } else {
              std::cout << std::endl
                        << "Sold " << quant << " of "
                        << m_inventory[static_cast<size_t>(choice[0] - 49)]
                               .first->get_name()
                        << " for "
                        << static_cast<size_t>(
                               m_inventory[static_cast<size_t>(choice[0] - 49)]
                                   .first->get_price()
                           ) * static_cast<size_t>(quant[0] - 48)
                        << " golds" << std::endl;
              m_gold += m_inventory[static_cast<size_t>(choice[0] - 49)]
                            .first->get_price() *
                        static_cast<int>(quant[0] - 48);
              remove_elem(
                  static_cast<size_t>(choice[0] - 49),
                  static_cast<int>(quant[0] - 48)
              );
            }
          }
          std::cout << "Press enter to continue. . .";
          getchar();
        }
        Utils::clear_screen();
      }
      Utils::clear_screen();
      show_shop_options();
    } else {
      Utils::clear_screen();
      std::cout << "Inventory empty !" << std::endl;
      std::cout << "Press enter to continue. . .";
      getchar();
      Utils::clear_screen();
      show_shop_options();
    }
  } else {
    Utils::clear_screen();
    show_Town_actions();
  }
}

Item *Hero::get_right_hand()
{
  if(m_right_hand.size() > 0) {
    return m_right_hand.back();
  }

  return nullptr;
}

void Hero::give_xp(int amount)
{
  m_xp += amount;
}

void Hero::level_up()
{
  m_xp = 0;
  m_level++;
  Utils::clear_screen();
  std::string choice = "0";
  while(choice == "0" || (choice != "1" && choice != "2")) {
    std::cout << "[LEVEL UP!]" << std::endl << std::endl;
    std::cout << "Choose which one to increase: " << std::endl;
    std::cout << "1. " << color(ColorType::LYELLOW) << "+1 Damage"
              << color(ColorType::DEFAULT) << std::endl;
    std::cout << "2. " << color(ColorType::LYELLOW) << "+1 Health Point"
              << color(ColorType::DEFAULT) << std::endl;
    std::cout << "Your choice: ";
    std::getline(std::cin, choice);
    Utils::clear_screen();
  }
  if(choice == "1") {
    m_atk++;
  } else if(choice == "2") {
    m_max_hp++;
  }
  m_hp = m_max_hp;
}

int Hero::get_xp_to_lvl()
{
  return static_cast<int>(
             round(0.05 * (m_level ^ 3) + 0.8 * (m_level ^ 2) + 2 * m_level)
         ) +
         15;
}

int Hero::compute_xp_needed()
{
  int actual_xp = m_xp;
  int needed    = m_xp_to_levelup;
  int xp        = needed - actual_xp;
  if(xp <= 0) {
    return 0;
  } else {
    return xp;
  }
}

int Hero::get_atk()
{
  return m_atk;
}

int Hero::get_total_dmg()
{
  int temp_atk  = 0;
  int temp_crit = 0;

  temp_atk += m_atk;
  temp_crit += m_crit_rate;
  srand(static_cast<unsigned int>(time(0)));
  if(rand() % 100 < (temp_crit)) {
    return temp_atk * 2;
  } else {
    return temp_atk;
  }
}

int Hero::get_status_rate()
{
  return m_status_rate;
}
