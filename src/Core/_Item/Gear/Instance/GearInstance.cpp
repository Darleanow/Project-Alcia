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
