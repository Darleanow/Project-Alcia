#include "GearInstance.h"

GearInstance::GearInstance(const Gear &gear, Stats final_stats)
    : m_gear(gear),
      m_final_stats(final_stats)
{
}

Stats GearInstance::get_stats() const
{
  return m_final_stats;
}

const Gear &GearInstance::get_gear() const
{
  return m_gear;
}

std::unique_ptr<Item> GearInstance::get_item() const
{
  return std::make_unique<Item>(
      m_gear.get_name(), m_gear.get_description(), m_gear.get_rarity(),
      m_gear.get_type(), m_gear.get_price()
  );
}
