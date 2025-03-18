#pragma once

#include "../../Item.h"
#include "../CoreDefinitions.h"
#include <memory>
#include <unordered_map>

class Equipment
{
public:
  Equipment()  = default;
  ~Equipment() = default;

  std::unique_ptr<Item>
      equip_item(EquipmentLocation slot, std::unique_ptr<Item> item);
  std::unique_ptr<Item> unequip_item(EquipmentLocation slot);
  const Item           *get_item(EquipmentLocation slot) const;

  bool                  validate_slot(EquipmentLocation slot) const;

private:
  std::unordered_map<EquipmentLocation, std::unique_ptr<Item>> m_equipment;
};
