#pragma once

#include "../Item.h"
#include "../Mixins/CrafteableMixin.h"
#include "../Mixins/EquipeableMixin.h"
#include "Stats/Stats.h"

class Gear final : public CrafteableMixin<Gear>,
                   public EquipeableMixin<Gear>,
                   public Item
{
public:
  Gear(
      ItemRecipe recipe, EquipmentLocation equipment_location, std::string name,
      std::string description, Rarity rarity, int price, Stats low_range_stats,
      Stats high_range_stats
  );
  ~Gear() noexcept override = default;

  Stats get_low_stats_range() const;
  Stats get_high_stats_range() const;

private:
  Stats m_low_range_stats;
  Stats m_high_range_stats;
};
