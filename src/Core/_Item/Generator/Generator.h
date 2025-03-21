#pragma once

#include <random>
#include <type_traits>

#include "../Gear/Gear.h"
#include "../Gear/Instance/GearInstance.h"
#include "Stats/Stats.h"

class Generator
{
public:
  static GearInstance generate_random_gear(const Gear &template_ref)
  {
    const auto  &low_range  = template_ref.get_low_stats_range();
    const auto  &high_range = template_ref.get_high_stats_range();

    GearInstance gear(
        template_ref, generate_random_stats_in_range(
                          low_range.get_stats(), high_range.get_stats()
                      )
    );

    return gear;
  }

  static Stats generate_random_stats_in_range(
      const StatsValues &low_range, const StatsValues &high_range
  )
  {
    StatsValues stat_values {
        .health = generate_random_in_range(low_range.health, high_range.health),
        .max_health = generate_random_in_range(
            low_range.max_health, high_range.max_health
        ),
        .attack = generate_random_in_range(low_range.attack, high_range.attack),
        .defense =
            generate_random_in_range(low_range.defense, high_range.defense),
        .crit_rate =
            generate_random_in_range(low_range.crit_rate, high_range.crit_rate),
        .crit_multiplier = generate_random_in_range(
            low_range.crit_multiplier, high_range.crit_multiplier
        ),
        .level = generate_random_in_range(low_range.level, high_range.level),
        .xp    = generate_random_in_range(low_range.xp, high_range.xp),
        .xp_to_level_up = generate_random_in_range(
            low_range.xp_to_level_up, high_range.xp_to_level_up
        )
    };

    Stats stats;
    stats.set_stats(stat_values);
    return stats;
  }

private:
  template <typename T>
  static T generate_random_in_range(T low, T high)
  {
    static std::random_device rd;
    static std::mt19937       gen(rd());

    if constexpr(std::is_integral_v<T>) {
      std::uniform_int_distribution<T> dist(low, high);
      return dist(gen);
    } else if constexpr(std::is_floating_point_v<T>) {
      std::uniform_real_distribution<T> dist(low, high);
      return dist(gen);
    } else {
      static_assert(
          std::is_arithmetic_v<T>, "Unsupported type for random generation"
      );
    }
  }
};
