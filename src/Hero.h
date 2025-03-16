#pragma once
#include "Core/Equipment/Equipment.h"
#include "Core/Inventory/Inventory.h"
#include "Core/Stats/Stats.h"
#include <cmath>
#include <memory>
#include <string>

#define BYE_THANKS_4_PLAY 0

class Hero
{
private:
  std::string m_name;
  int         m_gold                  = 100;
  int         m_status_rate           = 10;
  int         m_strength_potions_used = 0;

public:
  Hero(const std::string &name);
  ~Hero() = default;

  std::unique_ptr<Stats>     m_stats;
  std::unique_ptr<Equipment> m_equipment;
  std::unique_ptr<Inventory> m_inventory;

  int                        get_golds() const;

  std::string                get_name();

  void                       give_gold(int quantity);

  void                       show_inventory();

  int                        get_status_rate();

  int                        combat_main();
};
