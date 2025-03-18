#include "Equipment.h"

std::unique_ptr<Item>
    Equipment::equip_item(EquipmentLocation slot, std::unique_ptr<Item> item)
{
  if(!item || !validate_slot(slot)) {
    return nullptr;
  }

  auto previous_item = unequip_item(slot);
  m_equipment[slot]  = std::move(item);

  return previous_item;
}

std::unique_ptr<Item> Equipment::unequip_item(EquipmentLocation slot)
{
  auto it = m_equipment.find(slot);
  if(it == m_equipment.end()) {
    return nullptr;
  }

  auto item = std::move(it->second);
  m_equipment.erase(it);
  return item;
}

const Item *Equipment::get_item(EquipmentLocation slot) const
{
  auto it = m_equipment.find(slot);
  return (it != m_equipment.end()) ? it->second.get() : nullptr;
}

bool Equipment::validate_slot(EquipmentLocation slot) const
{
  switch(slot) {
  case EquipmentLocation::PrimaryHand:
  case EquipmentLocation::Helmet:
  case EquipmentLocation::Chestplate:
  case EquipmentLocation::Leggings:
  case EquipmentLocation::Boots:
    return true;
  default:
    return false;
  }
}
