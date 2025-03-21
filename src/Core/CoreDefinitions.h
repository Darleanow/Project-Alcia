#pragma once

#include <array>

enum class EquipmentLocation
{
  PrimaryHand = 0,
  Helmet      = 1,
  Chestplate  = 2,
  Leggings    = 3,
  Boots       = 4,
};

constexpr std::array<EquipmentLocation, 5> EquipmentLocationList = {
    EquipmentLocation::PrimaryHand, EquipmentLocation::Helmet,
    EquipmentLocation::Chestplate, EquipmentLocation::Leggings,
    EquipmentLocation::Boots
};

enum class Rarity
{
  Common    = 0,
  Rare      = 1,
  Epic      = 2,
  Legendary = 3
};

enum class ItemType
{
  Loot   = 0,
  Potion = 1,
  Weapon = 2,
  Armor  = 3,
};

enum class TargetType
{
  Self  = 0,
  Enemy = 1
};

enum class EffectType
{
  Instant      = 0,
  OverDuration = 1
};
