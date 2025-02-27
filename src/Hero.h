#pragma once
#include "Item.h"
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define BYE_THANKS_4_PLAY 0

class Hero
{
private:
  std::string         name;
  std::vector<Item *> inventory;
  int                 gold                  = 100;
  int                 hp                    = 20;
  int                 max_hp                = hp;
  int                 atk                   = 5;
  int                 crit_rate             = 5;
  int                 status_rate           = 10;
  int                 level                 = 1;
  int                 xp                    = 0;
  int                 xp_to_levelup         = get_xp_to_lvl();
  int                 strength_potions_used = 0;

  // Items holder
  std::vector<Item *> right_hand;
  std::vector<Item *> helmet;
  std::vector<Item *> chestplate;
  std::vector<Item *> pants;
  std::vector<Item *> boots;

public:
  // Returns hero's hp
  int  get_hp();
  int  get_max_hp();
  void set_hp(int quantity);
  void take_dmg(int quantity);

  // Set name and return name
  void        set_name(std::string name);
  std::string get_name();

  // Get items
  void give_gold(int quantity);
  void give(Item *item, int amount = 1);

  // Main menu actions
  void display_actions();

  // Show inventory and related actions
  void show_inventory();
  bool check(std::string name);
  int  check_quant(std::string item_name);
  void add(std::string name, int amount);
  void show_actions_inventory();
  void show_equipeable_items();
  void show_useable_items();
  void remove_elem(int index, int amount);
  void rem_by_name(std::string name, int quantity);
  void remove_from_inventory(Item *item);
  void delete_an_item();
  void equip(Item *item);
  void prompt_unequip();
  void unequip(int choice);

  // Town (Forge and shop)
  void show_Town_actions();
  void show_black_smith_actions();
  void show_shop_options();

  // Xp
  void give_xp(int amount);
  void level_up();
  int  get_level();
  int  get_xp_to_lvl();
  int  compute_xp_needed();

  // Damage
  int   get_atk();
  int   get_total_dmg();
  Item *get_right_hand();
  int   get_status_rate();

  // Instantiate combat
  int combat_main();
};
