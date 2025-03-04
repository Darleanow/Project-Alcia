#pragma once
#include "Hero.h"
#include "UI/SystemRelated.h"

class Monster
{
public:
  virtual ~Monster() = 0;

  virtual int         get_hp()                     = 0;
  virtual int         get_atk()                    = 0;
  virtual int         get_max_hp()                 = 0;
  virtual void        drop(Hero *player)           = 0;
  virtual std::string get_name()                   = 0;
  virtual int         take_dmg(Hero *hero)         = 0;
  virtual int         apply_status(Hero *hero)     = 0;
  virtual void        set_affected_rounds(int num) = 0;
};

class Zombie : public Monster
{
private:
  int         hp                       = generate_random_number(8, 17);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(2, 5);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Zombie";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class Skeletton : public Monster
{
private:
  int         hp                       = generate_random_number(14, 23);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(4, 12);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Skeletton";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class Troll : public Monster
{
private:
  int         hp                       = generate_random_number(20, 28);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(6, 13);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Troll";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class SuperTroll : public Monster
{
private:
  int         hp                       = generate_random_number(27, 39);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(4, 8);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "SUPAAA TROLL";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class Kobold : public Monster
{
private:
  int         hp                       = generate_random_number(15, 35);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(10, 18);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Kobold";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class Oreade : public Monster
{
private:
  int         hp                       = generate_random_number(15, 35);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(15, 20);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Oreade";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class BabyDragon : public Monster
{
private:
  int         hp                       = generate_random_number(30, 50);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(20, 30);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Baby Dragon";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class MamaDragon : public Monster
{
private:
  int         hp                       = generate_random_number(60, 100);
  int         max_hp                   = hp;
  int         atk                      = generate_random_number(35, 45);
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Mama Dragon";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};

class Azeael : public Monster
{
private:
  int         hp                       = 777;
  int         max_hp                   = 777;
  int         atk                      = 150;
  int         remained_rounds_affected = 0;
  bool        status                   = false;
  std::string name                     = "Azeael";

public:
  int         get_atk() override;
  int         get_hp() override;
  int         get_max_hp() override;
  void        drop(Hero *player) override;
  std::string get_name() override;
  void        set_affected_rounds(int num) override;
  int         apply_status(Hero *hero) override;
  int         take_dmg(Hero *hero) override;
};
