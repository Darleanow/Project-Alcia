#include "Monster.h"
#include "UI/Utils/DrawUtils.h"

#include <cstdio>
#include <iostream>

Monster::~Monster() = default;

int Zombie::get_atk()
{
  return this->atk;
}

int Zombie::get_hp()
{
  return this->hp;
}

std::string Zombie::get_name()
{
  return this->name;
}

int Zombie::get_max_hp()
{
  return this->max_hp;
}

void Zombie::drop(Hero *hero)
{
  hero->give_gold(this->get_max_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "- Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "- Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_flesh = generate_random_number(0, 3);
  if(!(hero->check("Zombie flesh"))) {
    if(amount_flesh > 0) {
      hero->give(new zombie_flesh);
      hero->add("Zombie flesh", amount_flesh - 1);
      std::cout << "- " << color(ColorType::GREEN) << "Zombie flesh "
                << color(ColorType::DEFAULT) << "x" << amount_flesh
                << std::endl;
    }
  } else {
    if(amount_flesh > 0) {
      hero->add("Zombie flesh", amount_flesh);
      std::cout << "- " << color(ColorType::GREEN) << "Zombie flesh "
                << color(ColorType::DEFAULT) << "x" << amount_flesh
                << std::endl;
    }
  }

  int amount_eye = generate_random_number(0, 2);
  if(roll_boolDice(40)) {
    if(amount_eye > 0) {
      if(!(hero->check("Zombie eye"))) {
        hero->give(new zombie_eye);
        hero->add("Zombie eye", amount_eye - 1);
      } else {
        hero->add("Zombie eye", amount_eye);
      }
      std::cout << "- " << color(ColorType::BLUE) << "Zombie eye "
                << color(ColorType::DEFAULT) << "x" << amount_eye << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

int Zombie::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int Zombie::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}

void Zombie::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

int Skeletton::get_atk()
{
  return this->atk;
}

int Skeletton::get_hp()
{
  return this->hp;
}

std::string Skeletton::get_name()
{
  return this->name;
}

int Skeletton::get_max_hp()
{
  return this->max_hp;
}

int Troll::get_atk()
{
  return this->atk;
}

int Troll::get_hp()
{
  return this->hp;
}

std::string Troll::get_name()
{
  return this->name;
}

int Troll::get_max_hp()
{
  return this->max_hp;
}

int SuperTroll::get_atk()
{
  return this->atk;
}

int SuperTroll::get_hp()
{
  return this->hp;
}

std::string SuperTroll::get_name()
{
  return this->name;
}

int SuperTroll::get_max_hp()
{
  return this->max_hp;
}

int Kobold::get_atk()
{
  return this->atk;
}

int Kobold::get_hp()
{
  return this->hp;
}

std::string Kobold::get_name()
{
  return this->name;
}

int Kobold::get_max_hp()
{
  return this->max_hp;
}

int Oreade::get_atk()
{
  return this->atk;
}

int Oreade::get_hp()
{
  return this->hp;
}

std::string Oreade::get_name()
{
  return this->name;
}

int Oreade::get_max_hp()
{
  return this->max_hp;
}

int BabyDragon::get_atk()
{
  return this->atk;
}

int BabyDragon::get_hp()
{
  return this->hp;
}

std::string BabyDragon::get_name()
{
  return this->name;
}

int BabyDragon::get_max_hp()
{
  return this->max_hp;
}

int MamaDragon::get_atk()
{
  return this->atk;
}

int MamaDragon::get_hp()
{
  return this->hp;
}

std::string MamaDragon::get_name()
{
  return this->name;
}

int MamaDragon::get_max_hp()
{
  return this->max_hp;
}

int Azeael::get_atk()
{
  return this->atk;
}

int Azeael::get_hp()
{
  return this->hp;
}

std::string Azeael::get_name()
{
  return this->name;
}

int Azeael::get_max_hp()
{
  return this->max_hp;
}

void Skeletton::drop(Hero *hero)
{
  hero->give_gold(this->get_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_bone_shard = generate_random_number(0, 5);
  if(!(hero->check("Bone shard"))) {
    if(amount_bone_shard > 0) {
      hero->give(new bone_shard);
      hero->add("Bone shard", amount_bone_shard - 1);
      std::cout << "-Bone shard(s) x" << amount_bone_shard << std::endl;
    }
  } else {
    if(amount_bone_shard > 0) {
      hero->add("Bone shard", amount_bone_shard);
      std::cout << "-Bone shard(s) x" << amount_bone_shard << std::endl;
    }
  }

  int amount_bone = generate_random_number(0, 2);
  if(roll_boolDice(30)) {
    if(amount_bone > 0) {
      if(!(hero->check("Bone"))) {
        hero->give(new bones);
        hero->add("Bone", amount_bone - 1);
        std::cout << "-Bone x" << amount_bone << std::endl;
      } else {
        hero->add("Bone", amount_bone);
        std::cout << "-Bone x" << amount_bone << std::endl;
      }
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

void Skeletton::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

void Troll::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

void SuperTroll::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

void Kobold::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

void Oreade::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

void BabyDragon::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

void MamaDragon::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

void Azeael::set_affected_rounds(int num)
{
  this->remained_rounds_affected = num;
}

int Skeletton::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int Troll::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int SuperTroll::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int Kobold::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int Oreade::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int BabyDragon::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int MamaDragon::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

int Azeael::apply_status(Hero *hero)
{
  std::string hero_status = hero->get_right_hand()->get_status();
  int         rate        = hero->get_status_rate();

  if(roll_boolDice(rate) && this->status == false) {
    if(hero_status == "Poison") {
      this->set_affected_rounds(4);
      this->status = true;
    } else if(hero_status == "Fire") {
      this->set_affected_rounds(2);
      this->status = true;
    } else if(hero_status == "Ice") {
      this->set_affected_rounds(1);
      this->status = true;
    } else if(hero_status == "Haunted") {
      this->set_affected_rounds(2);
      this->status = true;
    }
  }
  return 0;
}

void Troll::drop(Hero *hero)
{
  hero->give_gold(this->get_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_troll_finger = generate_random_number(0, 3);
  if(!(hero->check("Troll finger"))) {
    if(amount_troll_finger > 0) {
      hero->give(new troll_finger);
      hero->add("Troll finger", amount_troll_finger - 1);
      std::cout << "-Troll finger(s) x" << amount_troll_finger << std::endl;
    }
  } else {
    if(amount_troll_finger > 0) {
      hero->add("Troll finger", amount_troll_finger);
      std::cout << "-Troll finger(s) x" << amount_troll_finger << std::endl;
    }
  }

  int amount_empty_sack = generate_random_number(0, 1);
  if(roll_boolDice(30)) {
    if(amount_empty_sack > 0) {
      if(!(hero->check("Empty sack"))) {
        hero->give(new empty_sack);
        hero->add("Empty sack", amount_empty_sack - 1);
        std::cout << "-Empty sack x" << amount_empty_sack << std::endl;
      } else {
        hero->add("Empty sack", amount_empty_sack);
        std::cout << "-Empty sack x" << amount_empty_sack << std::endl;
      }
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

void SuperTroll::drop(Hero *hero)
{
  hero->give_gold(this->get_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_troll_finger = generate_random_number(0, 5);
  if(!(hero->check("Troll finger"))) {
    if(amount_troll_finger > 0) {
      hero->give(new troll_finger);
      hero->add("Troll finger", amount_troll_finger - 1);
      std::cout << "-Troll finger(s) x" << amount_troll_finger << std::endl;
    }
  } else {
    if(amount_troll_finger > 0) {
      hero->add("Troll finger", amount_troll_finger);
      std::cout << "-Troll finger(s) x" << amount_troll_finger << std::endl;
    }
  }

  int amount_troll_belt = generate_random_number(0, 1);
  if(roll_boolDice(30)) {
    if(amount_troll_belt > 0) {
      if(!(hero->check("Old belt"))) {
        hero->give(new troll_belt);
        hero->add("Old belt", amount_troll_belt - 1);
        std::cout << "-Old belt x" << amount_troll_belt << std::endl;
      } else {
        hero->add("Old belt", amount_troll_belt);
        std::cout << "-Old belt x" << amount_troll_belt << std::endl;
      }
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

void Kobold::drop(Hero *hero)
{
  hero->give_gold(this->get_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_kobold_tail = generate_random_number(0, 1);
  if(!(hero->check("Kobold tail"))) {
    if(amount_kobold_tail > 0) {
      hero->give(new kobold_tails);
      hero->add("Kobold tail", amount_kobold_tail - 1);
      std::cout << "-Kobold tail x" << amount_kobold_tail << std::endl;
    }
  } else {
    if(amount_kobold_tail > 0) {
      hero->add("Kobold tail", amount_kobold_tail);
      std::cout << "-Kobold tail x" << amount_kobold_tail << std::endl;
    }
  }

  int amount_kobold_scepter = generate_random_number(0, 1);
  if(roll_boolDice(10)) {
    if(amount_kobold_scepter > 0) {
      if(!(hero->check("Kobold Scepter"))) {
        hero->give(new kobold_scepter);
        hero->add("Kobold Scepter", amount_kobold_scepter - 1);
        std::cout << "-Kobold Scepter x" << amount_kobold_scepter << std::endl;
      } else {
        hero->add("Kobold Scepter", amount_kobold_scepter);
        std::cout << "-Kobold Scepter x" << amount_kobold_scepter << std::endl;
      }
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

void Oreade::drop(Hero *hero)
{
  hero->give_gold(this->get_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_oreade_powder = generate_random_number(2, 7);
  if(!(hero->check("Oreade powder"))) {
    if(amount_oreade_powder > 0) {
      hero->give(new oreade_powder);
      hero->add("Oreade powder", amount_oreade_powder - 1);
      std::cout << "-Oreade powder x" << amount_oreade_powder << std::endl;
    }
  } else {
    if(amount_oreade_powder > 0) {
      hero->add("Oreade powder", amount_oreade_powder);
      std::cout << "-Oreade powder x" << amount_oreade_powder << std::endl;
    }
  }

  int amount_magic_fragment = generate_random_number(0, 1);
  if(roll_boolDice(10)) {
    if(amount_magic_fragment > 0) {
      if(!(hero->check("Magic fragment"))) {
        hero->give(new magic_fragments);
      }
      hero->add("Magic fragment", amount_magic_fragment);
      std::cout << "-Magic fragment x" << amount_magic_fragment << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

void BabyDragon::drop(Hero *hero)
{
  hero->give_gold(this->get_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_scale = generate_random_number(0, 5);
  if(roll_boolDice(20)) {
    if(amount_scale > 0) {
      if(!(hero->check("Dragon scale"))) {
        hero->give(new dragon_scale);
      }
      hero->add("Dragon scale", amount_scale);
      std::cout << "-Dragon scale x" << amount_scale << std::endl;
    }
  }

  int amount_dragon_tooth = generate_random_number(0, 2);
  if(roll_boolDice(10)) {
    if(amount_dragon_tooth > 0) {
      if(!(hero->check("Dragon tooth"))) {
        hero->give(new dragon_tooth);
      }
      hero->add("Dragon tooth", amount_dragon_tooth);
      std::cout << "-Dragon tooth x" << amount_dragon_tooth << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
}

void MamaDragon::drop(Hero *hero)
{
  hero->give_gold(this->get_hp() + this->get_atk());
  hero->give_xp((this->get_max_hp() - 5) * 2);
  std::cout << "-Xp x" << (this->get_max_hp() - 5) * 2 << std::endl;
  std::cout << "-Gold x" << this->get_max_hp() + this->get_atk() << std::endl;

  int amount_scale = generate_random_number(0, 15);
  if(roll_boolDice(30)) {
    if(amount_scale > 0) {
      if(!(hero->check("Dragon scale"))) {
        hero->give(new dragon_scale);
      }
      hero->add("Dragon scale", amount_scale);
      std::cout << "-Dragon scale x" << amount_scale << std::endl;
    }
  }

  int amount_dragon_tooth = generate_random_number(0, 4);
  if(roll_boolDice(20)) {
    if(amount_dragon_tooth > 0) {
      if(!(hero->check("Dragon tooth"))) {
        hero->give(new dragon_tooth);
      }
      hero->add("Dragon tooth", amount_dragon_tooth);
      std::cout << "-Dragon tooth x" << amount_dragon_tooth << std::endl;
    }
  }

  std::cout << std::endl << std::endl;
  std::cout << "Press enter to continue. . .";
  getchar();
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
  std::cout << "Final Health: " << std::to_string(hero->get_max_hp())
            << std::endl;
  exit(BYE_THANKS_4_PLAY);
}

int Skeletton::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}

int Troll::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}

int SuperTroll::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}

int Kobold::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}

int Oreade::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}

int BabyDragon::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}

int MamaDragon::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Fire") {
      this->hp -= hero->get_total_dmg() / 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Haunted") {
      if(roll_boolDice(25)) {
        actual_attack /= 2;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}
int Azeael::take_dmg(Hero *hero)
{
  bool will_attk     = true;
  int  actual_attack = this->get_atk();
  this->hp -= hero->get_total_dmg();
  if(this->status) {
    std::string hero_status = hero->get_right_hand()->get_status();
    if(hero_status == "Poison") {
      this->hp -= (this->hp / 100) * 5;
    } else if(hero_status == "Ice") {
      if(roll_boolDice(50)) {
        will_attk = false;
      }
    } else if(hero_status == "Nature") {
      hero->set_hp((hero->get_hp() / 100) * 5);
    }
  }
  if(will_attk && this->hp > 0) {
    hero->take_dmg(actual_attack);
  }
  return 0;
}
