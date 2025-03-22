#include "Item/Gear/Gear.h"

class GearInstance
{
public:
  GearInstance(const Gear &gear, Stats final_stats);
  ~GearInstance() = default;

  Stats                 get_stats() const;
  const Gear           &get_gear() const;
  std::unique_ptr<Item> get_item() const;

private:
  const Gear &m_gear;
  Stats       m_final_stats;
};
