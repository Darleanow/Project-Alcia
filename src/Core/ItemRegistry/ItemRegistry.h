#pragma once

#include "Item/Gear/Gear.h"
#include <memory>
#include <unordered_map>

class Item;
class GearInstance;

class ItemRegistry
{
public:
  static ItemRegistry &get()
  {
    static ItemRegistry registry;
    return registry;
  }

  void                          register_item(std::shared_ptr<Item> item);

  std::shared_ptr<Item>         get_item(const std::string &name) const;

  std::unique_ptr<GearInstance> generate_random_item(int player_level) const;

private:
  std::unordered_map<std::string, std::shared_ptr<Item>> m_items;

  std::unique_ptr<GearInstance>     generate_item(const Gear &gear) const;

  std::unordered_map<Rarity, float> get_rarity_weights(int player_level) const;
};
