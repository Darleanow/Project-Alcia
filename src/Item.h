#pragma once
#include <string>

enum class ItemLocationEquipType
{
  PrimaryHand = 0,
  Helmet      = 1,
  Chestplate  = 2,
  Leggings    = 3,
  Boots       = 4,
  Potion      = 5,
  Loot        = 6
};

class Item
{
protected:
  std::string           name;
  ItemLocationEquipType type;
  std::string           rarity;
  std::string           status;
  int                   atk;
  int                   crit_rate;
  int                   hp;
  int                   price;

public:
  Item(
      const std::string &name, ItemLocationEquipType type,
      const std::string &rarity, const std::string &status, int atk,
      int crit_rate, int hp, int price
  );
  virtual ~Item() = default;

  std::string           get_name() const;
  ItemLocationEquipType get_type() const;
  std::string           get_rarity() const;
  std::string           get_status() const;
  int                   get_atk() const;
  int                   get_crit_rate() const;
  int                   get_hp() const;
  int                   get_price() const;
};

class CommonSword : public Item
{
public:
  CommonSword();
};

class RareSword : public Item
{
public:
  RareSword();
};

class EpicSword : public Item
{
public:
  EpicSword();
};

class LegendarySword : public Item
{
public:
  LegendarySword();
};

class CommonHelmet : public Item
{
public:
  CommonHelmet();
};

class RareHelmet : public Item
{
public:
  RareHelmet();
};

class EpicHelmet : public Item
{
public:
  EpicHelmet();
};

class LegendaryHelmet : public Item
{
public:
  LegendaryHelmet();
};

class CommonChestplate : public Item
{
public:
  CommonChestplate();
};

class RareChestplate : public Item
{
public:
  RareChestplate();
};

class EpicChestplate : public Item
{
public:
  EpicChestplate();
};

class LegendaryChestplate : public Item
{
public:
  LegendaryChestplate();
};

class CommonLeggings : public Item
{
public:
  CommonLeggings();
};

class RareLeggings : public Item
{
public:
  RareLeggings();
};

class EpicLeggings : public Item
{
public:
  EpicLeggings();
};

class LegendaryLeggings : public Item
{
public:
  LegendaryLeggings();
};

class CommonBoots : public Item
{
public:
  CommonBoots();
};

class RareBoots : public Item
{
public:
  RareBoots();
};

class EpicBoots : public Item
{
public:
  EpicBoots();
};

class LegendaryBoots : public Item
{
public:
  LegendaryBoots();
};

class HealthPotion : public Item
{
public:
  HealthPotion();
};

class StrengthPotion : public Item
{
public:
  StrengthPotion();
};

class ZombieFlesh : public Item
{
public:
  ZombieFlesh();
};

class ZombieEye : public Item
{
public:
  ZombieEye();
};

class BoneShard : public Item
{
public:
  BoneShard();
};

class Bones : public Item
{
public:
  Bones();
};

class TrollFinger : public Item
{
public:
  TrollFinger();
};

class EmptySack : public Item
{
public:
  EmptySack();
};

class TrollBelt : public Item
{
public:
  TrollBelt();
};

class KoboldTails : public Item
{
public:
  KoboldTails();
};

class KoboldScepter : public Item
{
public:
  KoboldScepter();
};

class OreadePowder : public Item
{
public:
  OreadePowder();
};

class MagicFragments : public Item
{
public:
  MagicFragments();
};

class DragonScale : public Item
{
public:
  DragonScale();
};

class DragonTooth : public Item
{
public:
  DragonTooth();
};

class AzeaelHead : public Item
{
public:
  AzeaelHead();
};

