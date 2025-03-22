#include "ItemRegistry.h"
#include "Item/Generator/Generator.h"
#include "Item/Item.h"
#include <random>

void ItemRegistry::register_item(std::shared_ptr<Item> item)
{
  auto item_name     = item->get_name();
  m_items[item_name] = item;
}

std::shared_ptr<Item> ItemRegistry::get_item(const std::string &name) const
{
  return m_items.count(name) ? m_items.at(name) : nullptr;
}

std::unique_ptr<GearInstance>
    ItemRegistry::generate_random_item(int player_level) const
{
  auto rarity_weights = get_rarity_weights(player_level);

  std::unordered_map<Rarity, std::vector<std::shared_ptr<Gear>>>
      gears_by_rarity;

  for(const auto &[name, item] : m_items) {
    std::shared_ptr<Gear> gear = std::dynamic_pointer_cast<Gear>(item);
    if(gear) {
      ItemType type = gear->get_type();
      if(type == ItemType::Weapon || type == ItemType::Armor) {
        gears_by_rarity[gear->get_rarity()].push_back(gear);
      }
    }
  }

  std::random_device  rd;
  std::mt19937        gen(rd());

  std::vector<Rarity> rarities;
  std::vector<float>  weights;

  for(auto &[rarity, weight] : rarity_weights) {
    if(!gears_by_rarity[rarity].empty()) {
      rarities.push_back(rarity);
      weights.push_back(weight);
    }
  }

  if(rarities.empty()) {
    throw std::runtime_error("No available gears to generate.");
  }

  std::discrete_distribution<>    rarity_dist(weights.begin(), weights.end());
  Rarity                          selected_rarity = rarities[rarity_dist(gen)];

  const auto                     &gears = gears_by_rarity[selected_rarity];

  std::uniform_int_distribution<> item_dist(
      0, static_cast<int>(gears.size()) - 1
  );

  return generate_item(*gears[item_dist(gen)].get());
}

std::unique_ptr<GearInstance> ItemRegistry::generate_item(const Gear &gear
) const
{
  return std::make_unique<GearInstance>(Generator::generate_random_gear(gear));
}

std::unordered_map<Rarity, float>
    ItemRegistry::get_rarity_weights(int player_level) const
{
  float lvl       = std::clamp(static_cast<float>(player_level), 1.0f, 100.0f);
  float legendary = std::clamp(0.001f + 0.049f * (lvl / 100.0f), 0.001f, 0.05f);
  float remaining = 1.0f - legendary;

  float common = std::clamp(0.85f - 0.55f * (lvl / 100.0f), 0.3f, 0.85f);
  float rare   = std::clamp(0.10f + 0.20f * (lvl / 100.0f), 0.1f, 0.3f);
  float epic   = remaining - common - rare;

  if(epic < 0.f)
    epic = 0.f;

  return {
      {Rarity::Common,    common   },
      {Rarity::Rare,      rare     },
      {Rarity::Epic,      epic     },
      {Rarity::Legendary, legendary},
  };
}
