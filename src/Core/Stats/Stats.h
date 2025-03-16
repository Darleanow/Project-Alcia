#pragma once

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
    health += other.health ? other.health : 0;
    max_health += other.max_health ? other.max_health : 0;
    attack += other.attack ? other.attack : 0;
    defense += other.defense ? other.defense : 0;
    crit_rate += other.crit_rate ? other.crit_rate : 0;
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
