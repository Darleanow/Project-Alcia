#include "Gear.h"
#include <optional>

Gear::Gear(
    ItemRecipe recipe, EquipmentLocation equipment_location, std::string name,
    std::string description, Rarity rarity, ItemType type, int price,
    Stats low_range_stats, Stats high_range_stats
)
    : CrafteableMixin<Gear>(std::move(recipe)),
      EquipeableMixin<Gear>(std::move(equipment_location)),

      Item(
          std::move(name), std::move(description), rarity, type, price
      )
{
}

Stats Gear::get_low_stats_range() const
{
  return m_low_range_stats;
}

Stats Gear::get_high_stats_range() const
{
  return m_high_range_stats;
}
