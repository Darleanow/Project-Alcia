#pragma once

#include "Hero.h"

class Monster
{
protected:
  std::string name;
  int         hp;
  int         max_hp;
  int         atk;
  int         remained_rounds_affected;
  bool        status;

public:
  virtual ~Monster() = 0;

  virtual int         get_hp() const;
  virtual int         get_atk() const;
  virtual int         get_max_hp() const;
  virtual std::string get_name() const;
  virtual void        drop(Hero *player) = 0;
  virtual int         take_dmg(Hero *hero);
  virtual int         apply_status(Hero *hero);
  virtual void        set_affected_rounds(int num);
};

class Zombie : public Monster
{
public:
  Zombie();
  void drop(Hero *player) override;
};

class Skeletton : public Monster
{
public:
  Skeletton();
  void drop(Hero *player) override;
};

class Troll : public Monster
{
public:
  Troll();
  void drop(Hero *player) override;
};

class SuperTroll : public Monster
{
public:
  SuperTroll();
  void drop(Hero *player) override;
};

class Kobold : public Monster
{
public:
  Kobold();
  void drop(Hero *player) override;
};

class Oreade : public Monster
{
public:
  Oreade();
  void drop(Hero *player) override;
};

class BabyDragon : public Monster
{
public:
  BabyDragon();
  void drop(Hero *player) override;
};

class MamaDragon : public Monster
{
public:
  MamaDragon();
  void drop(Hero *player) override;
};

class Azeael : public Monster
{
public:
  Azeael();
  void drop(Hero *player) override;
};
