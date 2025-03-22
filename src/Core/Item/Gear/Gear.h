#pragma once

#include "Item/Item.h"
#include "Item/Mixins/CrafteableMixin.h"
#include "Item/Mixins/EquipeableMixin.h"
#include "Stats/Stats.h"

class Gear final : public CrafteableMixin<Gear>,
                   public EquipeableMixin<Gear>,
                   public Item
{
public:
  Gear(
      ItemRecipe recipe, EquipmentLocation equipment_location, std::string name,
      std::string description, Rarity rarity, ItemType type, int price,
      Stats low_range_stats, Stats high_range_stats
  );
  ~Gear() noexcept override = default;

  Stats get_low_stats_range() const;
  Stats get_high_stats_range() const;

private:
  Stats m_low_range_stats;
  Stats m_high_range_stats;
};
