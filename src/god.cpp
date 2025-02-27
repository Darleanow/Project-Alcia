#include "god.h"

Monster *generate_monster(Hero *hero)
{
  std::mt19937           gen(std::random_device {}());

  std::vector<Monster *> monsters = {
      new Zombie, new Skeletton,  new Troll,      new SuperTroll, new Kobold,
      new Oreade, new BabyDragon, new MamaDragon, new Azeael
  };
  std::vector<double> chances {
      hero->get_level() > 20 ? 5 : 120 - hero->get_level() * 2.1,
      hero->get_level() > 30 ? 10 : 25 - hero->get_level() * 1.5,
      hero->get_level() > 45 ? 10 : 5 + hero->get_level() * 0.5,
      hero->get_level() > 50 ? 15 : 0.8 + hero->get_level() * 0.25,
      hero->get_level() > 55 ? 20 : 0.7 + hero->get_level() * 0.1,
      hero->get_level() > 60 ? 20 : 0.6 + hero->get_level() * 0.08,
      hero->get_level() > 65 ? 30 : 0.5 + hero->get_level() * 0.05,
      hero->get_level() > 70 ? 35 : 0.1 + hero->get_level() * 0.03,
      hero->get_level() > 90 ? 40 : 0.01 + hero->get_level() * 0.01,
  };

  std::discrete_distribution<std::size_t> d {chances.begin(), chances.end()};
  auto                                    sampled_value = monsters[d(gen)];

  return sampled_value;
}

Item *generate_item()
{
  std::mt19937        gen(std::random_device {}());

  std::vector<Item *> items = {
      new Common_Sword,     new Rare_Sword,        new Epic_Sword,
      new Legendary_Sword,  new Common_Boots,      new Rare_Boots,
      new Epic_Boots,       new Legendary_Boots,   new Common_Chestplate,
      new Rare_Chestplate,  new Epic_Chestplate,   new Legendary_Chestplate,
      new Common_Helmet,    new Rare_Helmet,       new Epic_Helmet,
      new Legendary_Helmet, new Common_Leggings,   new Rare_Leggings,
      new Epic_Leggings,    new Legendary_Leggings
  };

  std::vector<double> chances {20, 5,   2,  0.2, 20, 5,   2,  0.5, 20, 5,
                               2,  0.5, 20, 5,   2,  0.5, 20, 5,   2,  0.5};

  std::discrete_distribution<std::size_t> d {chances.begin(), chances.end()};
  auto                                    sampled_value = items[d(gen)];

  return sampled_value;
}

Item *random_item(std::vector<Item *> items, std::vector<size_t> odds)
{
  std::mt19937                            gen(std::random_device {}());

  std::discrete_distribution<std::size_t> d {odds.begin(), odds.end()};

  Item                                   *item_rand = items[d(gen)];

  return item_rand;
}
