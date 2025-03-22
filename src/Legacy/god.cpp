#include "god.h"

#include <random>

Monster *generate_monster(Hero *hero)
{
  std::mt19937           gen(std::random_device {}());

  std::vector<Monster *> monsters = {new Zombie,     new Skeletton, new Troll,
                                     new SuperTroll, new Kobold,    new Oreade,
                                     new Dragon,     new Azeael};
  std::vector<double>    chances {
      hero->m_stats.get()->get_stats().level > 20
             ? 5
             : 120 - hero->m_stats.get()->get_stats().level * 2.1,
      hero->m_stats.get()->get_stats().level > 30
          ? 10
          : 25 - hero->m_stats.get()->get_stats().level * 1.5,
      hero->m_stats.get()->get_stats().level > 45
          ? 10
          : 5 + hero->m_stats.get()->get_stats().level * 0.5,
      hero->m_stats.get()->get_stats().level > 50
          ? 15
          : 0.8 + hero->m_stats.get()->get_stats().level * 0.25,
      hero->m_stats.get()->get_stats().level > 55
          ? 20
          : 0.7 + hero->m_stats.get()->get_stats().level * 0.1,
      hero->m_stats.get()->get_stats().level > 60
          ? 20
          : 0.6 + hero->m_stats.get()->get_stats().level * 0.08,
      hero->m_stats.get()->get_stats().level > 65
          ? 30
          : 0.5 + hero->m_stats.get()->get_stats().level * 0.05,
      hero->m_stats.get()->get_stats().level > 90
          ? 40
          : 0.01 + hero->m_stats.get()->get_stats().level * 0.01,
  };

  std::discrete_distribution<std::size_t> d {chances.begin(), chances.end()};
  auto                                    sampled_value = monsters[d(gen)];

  return sampled_value;
}
