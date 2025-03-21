#pragma once

#include "CoreDefinitions.h"

#include <memory>

class Item;

template <typename T>
class EquipeableMixin
{
public:
  EquipeableMixin(EquipmentLocation equipment_location)
      : m_location(equipment_location) {};
  ~EquipeableMixin() = default;

  std::pair<EquipmentLocation, std::unique_ptr<T>> get()
  {
    return {m_location, std::make_unique<T>(static_cast<const T &>(*this))};
  }

private:
  EquipmentLocation m_location;
};
