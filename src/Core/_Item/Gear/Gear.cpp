#include "Gear.h"

Gear::Gear(
    ItemRecipe recipe, EquipmentLocation equipment_location, std::string name,
    std::string description, int price, Stats stats
)
    : CrafteableMixin<Gear>(std::move(recipe)),
      EquipeableMixin<Gear>(std::move(equipment_location)),
      Item(std::move(name), std::move(description), price)
{
}
