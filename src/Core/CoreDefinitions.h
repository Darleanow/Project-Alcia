#pragma once

#include <array>

enum class EquipmentLocation
{
  PrimaryHand = 0,
  Helmet      = 1,
  Chestplate  = 2,
  Leggings    = 3,
  Boots       = 4,
  Potion      = 5,
  Loot        = 6
};

constexpr std::array<EquipmentLocation, 5> EquipmentLocationList = {
    EquipmentLocation::PrimaryHand, EquipmentLocation::Helmet,
    EquipmentLocation::Chestplate, EquipmentLocation::Leggings,
    EquipmentLocation::Boots
};
