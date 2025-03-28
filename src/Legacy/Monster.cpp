#include "Monster.h"
#include "CoreDefinitions.h"
#include "SystemRelated.h"
#include "Utils/DrawUtils.h"

#include <cstdio>
#include <iostream>

Monster::~Monster() = default;

int Monster::get_hp() const
{
  return hp;
}

int Monster::get_atk() const
{
  return atk;
}

std::string Monster::get_name() const
{
  return name;
}

int Monster::get_max_hp() const
{
  return max_hp;
}

void Monster::set_affected_rounds(int num)
{
  remained_rounds_affected = num;
}

int Monster::apply_status(Hero *hero)
{
  std::string hero_status =
      hero->m_equipment->get_item(EquipmentLocation::PrimaryHand)->get_status();
  int rate = hero->get_status_rate();

  if(roll_boolDice(rate) && status == false) {
    if(hero_status == "Poison") {
      set_affected_rounds(4);
      status = true;
    } else if(hero_status == "Fire") {
      set_affected_rounds(2);
      status = true;
    } else if(hero_status == "Ice") {
      set_affected_rounds(1);
      status = true;
    } else if(hero_status == "Haunted") {
      set_affected_rounds(2);
      status = true;
    }
  }
  return 0;
}

int Monster::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = get_atk();
  hp -= hero->m_stats->compute_attack_damage();
  if(status) {
    std::string hero_status =
        hero->m_equipment->get_item(EquipmentLocation::PrimaryHand)
            ->get_status();
    if(hero_status == "Poison") {
      hp -= (hp / 100) * 5;
    } else if(hero_status == "Fire") {
      hp -= hero->m_stats->compute_attack_damage() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->m_stats->heal((hero->m_stats->get_stats().health / 100) * 5);
    }
  }

  if(will_attk && hp > 0) {
    hero->m_stats->take_damage(actual_attack);
  }

  return 0;
}

Zombie::Zombie()
{
  name                     = "Zombie";
  hp                       = generate_random_number(8, 17);
  max_hp                   = hp;
  atk                      = generate_random_number(2, 5);
  remained_rounds_affected = 0;
  status                   = false;
}

void Zombie::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp(get_max_hp() - 5 * 2);
  std::cout << "- Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "- Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_flesh = generate_random_number(0, 3);
  if(amount_flesh > 0) {
    hero->m_inventory->add_item(std::make_unique<ZombieFlesh>(), amount_flesh);
    std::cout << "- " << color(ColorType::GREEN) << "Zombie flesh "
              << color(ColorType::DEFAULT) << "x" << amount_flesh << std::endl;
  }

  int amount_eye = generate_random_number(1, 2);
  if(roll_boolDice(40)) {
    if(amount_eye > 0) {
      hero->m_inventory->add_item(std::make_unique<ZombieEye>(), amount_eye);
      std::cout << "- " << color(ColorType::BLUE) << "Zombie eye "
                << color(ColorType::DEFAULT) << "x" << amount_eye << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

Skeletton::Skeletton()
{
  name                     = "Skeletton";
  hp                       = generate_random_number(14, 23);
  max_hp                   = hp;
  atk                      = generate_random_number(4, 12);
  remained_rounds_affected = 0;
  status                   = false;
}

void Skeletton::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp((get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_bone_shard = generate_random_number(0, 5);
  if(amount_bone_shard > 0) {
    hero->m_inventory->add_item(
        std::make_unique<BoneShard>(), amount_bone_shard
    );
    std::cout << "-Bone shard(s) x" << amount_bone_shard << std::endl;
  }

  int amount_bone = generate_random_number(0, 2);
  if(roll_boolDice(30)) {
    if(amount_bone > 0) {
      hero->m_inventory->add_item(std::make_unique<Bones>(), amount_bone);
      std::cout << "-Bone x" << amount_bone << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

Troll::Troll()
{
  name                     = "Troll";
  hp                       = generate_random_number(20, 28);
  max_hp                   = hp;
  atk                      = generate_random_number(6, 13);
  remained_rounds_affected = 0;
  status                   = false;
}

void Troll::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp((get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_troll_finger = generate_random_number(0, 3);
  if(amount_troll_finger > 0) {
    hero->m_inventory->add_item(
        std::make_unique<TrollFinger>(), amount_troll_finger
    );
    std::cout << "-Troll finger(s) x" << amount_troll_finger << std::endl;
  }

  int amount_empty_sack = generate_random_number(0, 1);
  if(roll_boolDice(30)) {
    if(amount_empty_sack > 0) {
      hero->m_inventory->add_item(
          std::make_unique<EmptySack>(), amount_empty_sack
      );
      std::cout << "-Empty sack x" << amount_empty_sack << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

SuperTroll::SuperTroll()
{
  name                     = "SUPAAA TROLL";
  hp                       = generate_random_number(27, 39);
  max_hp                   = hp;
  atk                      = generate_random_number(4, 8);
  remained_rounds_affected = 0;
  status                   = false;
}

void SuperTroll::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp((get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_troll_finger = generate_random_number(0, 5);
  if(amount_troll_finger > 0) {
    hero->m_inventory->add_item(
        std::make_unique<TrollFinger>(), amount_troll_finger
    );
    std::cout << "-Troll finger(s) x" << amount_troll_finger << std::endl;
  }

  int amount_troll_belt = generate_random_number(0, 1);
  if(roll_boolDice(30)) {
    if(amount_troll_belt > 0) {
      hero->m_inventory->add_item(
          std::make_unique<TrollBelt>(), amount_troll_belt
      );
      std::cout << "-Old belt x" << amount_troll_belt << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

Kobold::Kobold()
{
  name                     = "Kobold";
  hp                       = generate_random_number(15, 35);
  max_hp                   = hp;
  atk                      = generate_random_number(10, 18);
  remained_rounds_affected = 0;
  status                   = false;
}

void Kobold::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp((get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_kobold_tail = generate_random_number(0, 1);
  if(amount_kobold_tail > 0) {
    hero->m_inventory->add_item(
        std::make_unique<KoboldTails>(), amount_kobold_tail
    );
    std::cout << "-Kobold tail x" << amount_kobold_tail << std::endl;
  }

  int amount_kobold_scepter = generate_random_number(0, 1);
  if(roll_boolDice(10)) {
    if(amount_kobold_scepter > 0) {
      hero->m_inventory->add_item(
          std::make_unique<KoboldScepter>(), amount_kobold_scepter
      );
      std::cout << "-Kobold Scepter x" << amount_kobold_scepter << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

Oreade::Oreade()
{
  name                     = "Oreade";
  hp                       = generate_random_number(15, 35);
  max_hp                   = hp;
  atk                      = generate_random_number(15, 20);
  remained_rounds_affected = 0;
  status                   = false;
}

void Oreade::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp((get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_oreade_powder = generate_random_number(2, 7);
  if(amount_oreade_powder > 0) {
    hero->m_inventory->add_item(
        std::make_unique<OreadePowder>(), amount_oreade_powder
    );
    std::cout << "-Oreade powder x" << amount_oreade_powder << std::endl;
  }

  int amount_magic_fragment = generate_random_number(0, 1);
  if(roll_boolDice(10)) {
    if(amount_magic_fragment > 0) {
      hero->m_inventory->add_item(
          std::make_unique<MagicFragments>(), amount_magic_fragment
      );
      std::cout << "-Magic fragment x" << amount_magic_fragment << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

BabyDragon::BabyDragon()
{
  name                     = "Baby Dragon";
  hp                       = generate_random_number(30, 50);
  max_hp                   = hp;
  atk                      = generate_random_number(20, 30);
  remained_rounds_affected = 0;
  status                   = false;
}

void BabyDragon::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp((get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_scale = generate_random_number(0, 5);
  if(roll_boolDice(20)) {
    if(amount_scale > 0) {
      hero->m_inventory->add_item(
          std::make_unique<DragonScale>(), amount_scale
      );
      std::cout << "-Dragon scale x" << amount_scale << std::endl;
    }
  }

  int amount_dragon_tooth = generate_random_number(0, 2);
  if(roll_boolDice(10)) {
    if(amount_dragon_tooth > 0) {
      hero->m_inventory->add_item(
          std::make_unique<DragonTooth>(), amount_dragon_tooth
      );
      std::cout << "-Dragon tooth x" << amount_dragon_tooth << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

MamaDragon::MamaDragon()
{
  name                     = "Mama Dragon";
  hp                       = generate_random_number(60, 100);
  max_hp                   = hp;
  atk                      = generate_random_number(35, 45);
  remained_rounds_affected = 0;
  status                   = false;
}

void MamaDragon::drop(Hero *hero)
{
  hero->give_gold(get_max_hp() + get_atk());
  hero->m_stats->earn_xp((get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << get_max_hp() + get_atk() << std::endl;

  int amount_scale = generate_random_number(0, 15);
  if(roll_boolDice(30)) {
    if(amount_scale > 0) {
      hero->m_inventory->add_item(
          std::make_unique<DragonScale>(), amount_scale
      );
      std::cout << "-Dragon scale x" << amount_scale << std::endl;
    }
  }

  int amount_dragon_tooth = generate_random_number(0, 4);
  if(roll_boolDice(20)) {
    if(amount_dragon_tooth > 0) {
      hero->m_inventory->add_item(
          std::make_unique<DragonTooth>(), amount_dragon_tooth
      );
      std::cout << "-Dragon tooth x" << amount_dragon_tooth << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

Azeael::Azeael()
{
  name                     = "Azeael";
  hp                       = 777;
  max_hp                   = 777;
  atk                      = 150;
  remained_rounds_affected = 0;
  status                   = false;
}

void Azeael::drop(Hero *hero)
{
  std::cout << "Congrats, you've beaten Azeael..." << std::endl;
  std::cout << "Light kisses your eyes...";
  getchar();
  std::cout << std::endl << "You slowly open them back again...";
  getchar();
  std::cout << std::endl << "And see that it was all a dream...";
  getchar();
  std::cout << std::endl << "The end !";
  getchar();

  std::cout << "Your stats" << std::endl;
  std::cout << "Final Health: "
            << std::to_string(hero->m_stats->get_stats().health) << std::endl;
  exit(BYE_THANKS_4_PLAY);
}
