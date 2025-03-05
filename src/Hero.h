#pragma once
#include "Item.h"
#include <cmath>
#include <string>
#include <vector>

#define BYE_THANKS_4_PLAY 0

class Hero
{
private:
  std::string         m_name;
  std::vector<Item *> m_inventory;
  int                 m_gold                  = 100;
  int                 m_hp                    = 20;
  int                 m_max_hp                = m_hp;
  int                 m_atk                   = 5;
  int                 m_crit_rate             = 5;
  int                 m_status_rate           = 10;
  int                 m_level                 = 1;
  int                 m_xp                    = 0;
  int                 m_xp_to_levelup         = get_xp_to_lvl();
  int                 m_strength_potions_used = 0;

  std::vector<Item *> m_right_hand;
  std::vector<Item *> m_helmet;
  std::vector<Item *> m_chestplate;
  std::vector<Item *> m_pants;
  std::vector<Item *> m_boots;

public:
  Hero(const std::string &name);
  ~Hero() = default;

  int         get_hp();
  int         get_max_hp();
  void        set_hp(int quantity);
  void        take_dmg(int quantity);

  std::string get_name();

  void        give_gold(int quantity);
  void        give(Item *item, int amount = 1);

  void        display_actions();

  void        show_inventory();
  bool        check(std::string name);
  int         check_quant(std::string item_name);
  void        add(std::string name, int amount);
  void        show_actions_inventory();
  void        show_equipeable_items();
  void        show_useable_items();
  void        remove_elem(size_t index, int amount);
  void        rem_by_name(std::string name, int quantity);
  void        remove_from_inventory(Item *item);
  void        delete_an_item();
  void        equip(Item *item);
  void        prompt_unequip();
  void        unequip(int choice);

  void        show_Town_actions();
  void        show_black_smith_actions();
  void        show_shop_options();

  void        give_xp(int amount);
  void        level_up();
  int         get_level();
  int         get_xp_to_lvl();
  int         compute_xp_needed();

  int         get_atk();
  int         get_total_dmg();
  Item       *get_right_hand();
  int         get_status_rate();

  int         combat_main();
};
