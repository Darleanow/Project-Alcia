#pragma once

#include "CoreDefinitions.h"

#include <array>
#include <optional>
#include <string_view>
#include <unordered_map>

namespace CoreUtils {

template <typename T, size_t N>
inline std::optional<T> lookup(
    std::string_view                                     key,
    const std::array<std::pair<std::string_view, T>, N> &mapping
)
{
  static const std::unordered_map<std::string_view, T> map(
      mapping.begin(), mapping.end()
  );

  if(auto it = map.find(key); it != map.end())
    return it->second;

  return std::nullopt;
}

inline std::optional<EquipmentLocation>
    string_to_equipment_location(std::string_view value)
{
  static constexpr std::array<std::pair<std::string_view, EquipmentLocation>, 5>
      mapping = {
          {{"primary_hand", EquipmentLocation::PrimaryHand},
           {"helmet", EquipmentLocation::Helmet},
           {"chestplate", EquipmentLocation::Chestplate},
           {"leggings", EquipmentLocation::Leggings},
           {"boots", EquipmentLocation::Boots}}
  };

  return lookup(value, mapping);
}

inline std::optional<Rarity> string_to_rarity(std::string_view rarity_string)
{
  static constexpr std::array<std::pair<std::string_view, Rarity>, 4> mapping =
      {
          {{"common", Rarity::Common},
           {"rare", Rarity::Rare},
           {"epic", Rarity::Epic},
           {"legendary", Rarity::Legendary}}
  };

  return lookup(rarity_string, mapping);
}

inline std::optional<ItemType> string_to_type(std::string_view type_string)
{
  static constexpr std::array<std::pair<std::string_view, ItemType>, 4>
      mapping = {
          {{"loot", ItemType::Loot},
           {"potion", ItemType::Potion},
           {"weapon", ItemType::Weapon},
           {"armor", ItemType::Armor}}
  };

  return lookup(type_string, mapping);
}

} // namespace CoreUtils
