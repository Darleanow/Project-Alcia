#include "Stats.h"

#include <algorithm>
#include <random>

Stats::Stats() = default;

void Stats::set_stats(const StatsValues &stats_values)
{
  m_stats = stats_values;
}

void Stats::add_stats(const StatsValues &stats_values)
{
  m_stats += stats_values;
}

StatsValues Stats::get_stats() const
{
  return m_stats;
}

void Stats::take_damage(int amount)
{
  m_stats.health -= amount;
}

void Stats::heal(int amount)
{
  m_stats.health = std::min(m_stats.max_health, m_stats.health + amount);
}

void Stats::earn_xp(int amount)
{
  m_stats.xp += amount;
}

int Stats::level_up()
{
  int level_up_amount = 0;

  while(m_stats.xp >= m_stats.xp_to_level_up) {
    m_stats.level++;
    m_stats.xp -= m_stats.xp_to_level_up;
    level_up_amount++;

    set_xp_needed_to_level_up(compute_xp_needed_to_next_level());

    m_stats.health = m_stats.max_health;
  }

  return level_up_amount;
}

int Stats::compute_attack_damage() const
{
  int                             total_damage = m_stats.attack;

  std::random_device              random_device;
  std::mt19937                    generator(random_device());
  std::uniform_int_distribution<> distribution(0, 100);

  if(distribution(generator) <= m_stats.crit_rate) {
    auto multiplied_damage =
        static_cast<float>(total_damage) * m_stats.crit_multiplier;

    total_damage = static_cast<int>(multiplied_damage);
  }

  return total_damage;
}

void Stats::compute_stats_from_item(StatsValues stats)
{
  add_stats(stats);
}

StatsValues negate(StatsValues stats)
{
  return StatsValues(
      {.health     = -stats.health,
       .max_health = -stats.max_health,
       .attack     = -stats.attack}
  );
}

void Stats::remove_stats_from_item(StatsValues stats)
{
  add_stats(negate(stats));
}

bool Stats::is_alive()
{
  return m_stats.health > 0;
}

int Stats::compute_xp_needed_to_next_level() const
{
  return static_cast<int>(round(
             0.05 * (m_stats.level ^ 3) + 0.8 * (m_stats.level ^ 2) +
             2 * m_stats.level
         )) +
         15;
}

void Stats::set_xp_needed_to_level_up(int xp_needed)
{
  m_stats.xp_to_level_up = xp_needed;
}
