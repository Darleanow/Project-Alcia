#include "../Gear.h"

class GearInstance
{
public:
  GearInstance(const Gear &gear, Stats final_stats);
  ~GearInstance() = default;

  Stats get_stats() const;

private:
  const Gear &m_gear;
  Stats       m_final_stats;
};
