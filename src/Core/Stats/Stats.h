#pragma once

#include <algorithm>

class Item;

struct StatsValues
{
  int          health          = 20;
  int          max_health      = 20;
  int          attack          = 5;
  int          defense         = 3;
  int          crit_rate       = 5;
  float        crit_multiplier = 1.5;
  int          level           = 1;
  int          xp              = 0;
  int          xp_to_level_up  = 0;

  StatsValues &operator+=(const StatsValues &other)
  {
    max_health += other.max_health;
    health = std::min(health + other.health, max_health);
    attack += other.attack;
    defense += other.defense;
    crit_rate += other.crit_rate;

    return *this;
  }
};

class Stats
{
public:
  Stats();
  ~Stats() = default;

  void        set_stats(const StatsValues &stats_values);
  void        add_stats(const StatsValues &stats_values);
  StatsValues get_stats() const;

  void        take_damage(int amount);
  void        heal(int amount);

  void        earn_xp(int amount);
  int         level_up();

  int         compute_attack_damage() const;

  bool        is_alive();

  void        compute_stats_from_item(StatsValues stats);
  void        remove_stats_from_item(StatsValues stats);

private:
  StatsValues m_stats;

  int         compute_xp_needed_to_next_level() const;
  void        set_xp_needed_to_level_up(int xp_needed);
};
