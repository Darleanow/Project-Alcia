#include "god.h"

#include <functional>
#include <random>

Monster *generate_monster(Hero *hero)
{
  std::mt19937           gen(std::random_device {}());

  std::vector<Monster *> monsters = {
      new Zombie, new Skeletton,  new Troll,      new SuperTroll, new Kobold,
      new Oreade, new BabyDragon, new MamaDragon, new Azeael
  };
  std::vector<double> chances {
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
      hero->m_stats.get()->get_stats().level > 70
          ? 35
          : 0.1 + hero->m_stats.get()->get_stats().level * 0.03,
      hero->m_stats.get()->get_stats().level > 90
          ? 40
          : 0.01 + hero->m_stats.get()->get_stats().level * 0.01,
  };

  std::discrete_distribution<std::size_t> d {chances.begin(), chances.end()};
  auto                                    sampled_value = monsters[d(gen)];

  return sampled_value;
}

std::unique_ptr<Item> generate_item()
{
  std::mt19937 gen(std::random_device {}());

  std::vector<std::function<std::unique_ptr<Item>()>> item_generators = {
      [] { return std::make_unique<CommonSword>(); },
      [] { return std::make_unique<RareSword>(); },
      [] { return std::make_unique<EpicSword>(); },
      [] { return std::make_unique<LegendarySword>(); },
      [] { return std::make_unique<CommonBoots>(); },
      [] { return std::make_unique<RareBoots>(); },
      [] { return std::make_unique<EpicBoots>(); },
      [] { return std::make_unique<LegendaryBoots>(); },
      [] { return std::make_unique<CommonChestplate>(); },
      [] { return std::make_unique<RareChestplate>(); },
      [] { return std::make_unique<EpicChestplate>(); },
      [] { return std::make_unique<LegendaryChestplate>(); },
      [] { return std::make_unique<CommonHelmet>(); },
      [] { return std::make_unique<RareHelmet>(); },
      [] { return std::make_unique<EpicHelmet>(); },
      [] { return std::make_unique<LegendaryHelmet>(); },
      [] { return std::make_unique<CommonLeggings>(); },
      [] { return std::make_unique<RareLeggings>(); },
      [] { return std::make_unique<EpicLeggings>(); },
      [] { return std::make_unique<LegendaryLeggings>(); }
  };

  std::vector<double> chances {20, 5,   2,  0.2, 20, 5,   2,  0.5, 20, 5,
                               2,  0.5, 20, 5,   2,  0.5, 20, 5,   2,  0.5};

  std::discrete_distribution<std::size_t> d(chances.begin(), chances.end());

  return item_generators[d(gen)]();
}

Item *random_item(std::vector<Item *> items, std::vector<size_t> odds)
{
  std::mt19937                            gen(std::random_device {}());

  std::discrete_distribution<std::size_t> d {odds.begin(), odds.end()};

  Item                                   *item_rand = items[d(gen)];

  return item_rand;
}
