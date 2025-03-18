#pragma once

#include "CoreDefinitions.h"

#include <optional>
#include <string_view>
#include <unordered_map>

namespace CoreUtils {

static inline std::optional<EquipmentLocation>
    to_equipment_location(std::string_view value)
{
  static const std::unordered_map<std::string_view, EquipmentLocation> mapping =
      {
          {"Primary Hand", EquipmentLocation::PrimaryHand},
          {"Helmet",       EquipmentLocation::Helmet     },
          {"Chestplate",   EquipmentLocation::Chestplate },
          {"Leggings",     EquipmentLocation::Leggings   },
          {"Boots",        EquipmentLocation::Boots      }
  };

  if(const auto it = mapping.find(value); it != mapping.end()) {
    return it->second;
  }

  return std::nullopt;
}

}; // namespace CoreUtils
