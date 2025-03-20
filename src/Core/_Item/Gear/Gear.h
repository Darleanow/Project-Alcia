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
      std::string description, int price, Stats stats
  );
  ~Gear() noexcept override = default;

private:
};
