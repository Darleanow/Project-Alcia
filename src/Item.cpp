#include "Item.h"

Item::Item(
    const std::string &name, ItemLocationEquipType type,
    const std::string &rarity, const std::string &status, int atk,
    int crit_rate, int hp, int price
)
    : name(name),
      type(type),
      rarity(rarity),
      status(status),
      atk(atk),
      crit_rate(crit_rate),
      hp(hp),
      price(price)
{
}

std::string Item::get_name() const
{
  return name;
}

ItemLocationEquipType Item::get_type() const
{
  return type;
}

std::string Item::get_rarity() const
{
  return rarity;
}

std::string Item::get_status() const
{
  return status;
}

int Item::get_atk() const
{
  return atk;
}

int Item::get_crit_rate() const
{
  return crit_rate;
}

int Item::get_hp() const
{
  return hp;
}

int Item::get_price() const
{
  return price;
}

CommonSword::CommonSword()
    : Item(
          "Common Sword", ItemLocationEquipType::PrimaryHand, "common", "", 5,
          10, 0, 150
      )
{
}

RareSword::RareSword()
    : Item(
          "Rare Sword", ItemLocationEquipType::PrimaryHand, "rare", "", 8, 15,
          0, 300
      )
{
}

EpicSword::EpicSword()
    : Item(
          "Epic Sword", ItemLocationEquipType::PrimaryHand, "epic", "", 15, 20,
          0, 600
      )
{
}

LegendarySword::LegendarySword()
    : Item(
          "Legendary Sword", ItemLocationEquipType::PrimaryHand, "legendary",
          "Fire", 35, 20, 0, 15000
      )
{
}

CommonHelmet::CommonHelmet()
    : Item(
          "Common Helmet", ItemLocationEquipType::Helmet, "common", "", 0, 0, 5,
          80
      )
{
}

RareHelmet::RareHelmet()
    : Item(
          "Rare Helmet", ItemLocationEquipType::Helmet, "rare", "", 0, 0, 8, 200
      )
{
}

EpicHelmet::EpicHelmet()
    : Item(
          "Epic Helmet", ItemLocationEquipType::Helmet, "epic", "", 0, 0, 10,
          380
      )
{
}

LegendaryHelmet::LegendaryHelmet()
    : Item(
          "Legendary Helmet", ItemLocationEquipType::Helmet, "legendary", "", 0,
          0, 15, 600
      )
{
}

CommonChestplate::CommonChestplate()
    : Item(
          "Common Chestplate", ItemLocationEquipType::Chestplate, "common", "",
          0, 0, 7, 80
      )
{
}

RareChestplate::RareChestplate()
    : Item(
          "Rare Chestplate", ItemLocationEquipType::Chestplate, "rare", "", 0,
          0, 12, 200
      )
{
}

EpicChestplate::EpicChestplate()
    : Item(
          "Epic Chestplate", ItemLocationEquipType::Chestplate, "epic", "", 0,
          0, 20, 380
      )
{
}

LegendaryChestplate::LegendaryChestplate()
    : Item(
          "Legendary Chestplate", ItemLocationEquipType::Chestplate,
          "legendary", "", 0, 0, 25, 1000
      )
{
}

CommonLeggings::CommonLeggings()
    : Item(
          "Common Leggings", ItemLocationEquipType::Leggings, "common", "", 0,
          0, 9, 80
      )
{
}

RareLeggings::RareLeggings()
    : Item(
          "Rare Leggings", ItemLocationEquipType::Leggings, "rare", "", 0, 0,
          11, 200
      )
{
}

EpicLeggings::EpicLeggings()
    : Item(
          "Epic Leggings", ItemLocationEquipType::Leggings, "epic", "", 0, 0,
          17, 380
      )
{
}

LegendaryLeggings::LegendaryLeggings()
    : Item(
          "Legendary Leggings", ItemLocationEquipType::Leggings, "legendary",
          "", 0, 0, 20, 600
      )
{
}

CommonBoots::CommonBoots()
    : Item(
          "Common Boots", ItemLocationEquipType::Boots, "common", "", 0, 0, 5,
          80
      )
{
}

RareBoots::RareBoots()
    : Item("Rare Boots", ItemLocationEquipType::Boots, "rare", "", 0, 0, 8, 200)
{
}

EpicBoots::EpicBoots()
    : Item(
          "Epic Boots", ItemLocationEquipType::Boots, "epic", "", 0, 0, 10, 380
      )
{
}

LegendaryBoots::LegendaryBoots()
    : Item(
          "Legendary Boots", ItemLocationEquipType::Boots, "legendary", "", 0,
          0, 15, 600
      )
{
}

HealthPotion::HealthPotion()
    : Item(
          "Health Potion", ItemLocationEquipType::Potion, "common", "", 0, 0,
          15, 50
      )
{
}

StrengthPotion::StrengthPotion()
    : Item(
          "Strength Potion", ItemLocationEquipType::Potion, "common", "", 15, 0,
          0, 120
      )
{
}

ZombieFlesh::ZombieFlesh()
    : Item(
          "Zombie Flesh", ItemLocationEquipType::Loot, "common", "", 0, 0, 0, 2
      )
{
}

ZombieEye::ZombieEye()
    : Item("Zombie Eye", ItemLocationEquipType::Loot, "rare", "", 0, 0, 0, 10)
{
}

BoneShard::BoneShard()
    : Item("Bone Shard", ItemLocationEquipType::Loot, "common", "", 0, 0, 0, 4)
{
}

Bones::Bones()
    : Item("Bones", ItemLocationEquipType::Loot, "rare", "", 0, 0, 0, 15)
{
}

TrollFinger::TrollFinger()
    : Item("Troll Finger", ItemLocationEquipType::Loot, "rare", "", 0, 0, 0, 25)
{
}

EmptySack::EmptySack()
    : Item("Empty Sack", ItemLocationEquipType::Loot, "rare", "", 0, 0, 0, 20)
{
}

TrollBelt::TrollBelt()
    : Item("Troll Belt", ItemLocationEquipType::Loot, "epic", "", 0, 0, 0, 60)
{
}

KoboldTails::KoboldTails()
    : Item("Kobold Tails", ItemLocationEquipType::Loot, "rare", "", 0, 0, 0, 30)
{
}

KoboldScepter::KoboldScepter()
    : Item(
          "Kobold Scepter", ItemLocationEquipType::Loot, "epic", "", 0, 0, 0, 64
      )
{
}

OreadePowder::OreadePowder()
    : Item(
          "Oreade Powder", ItemLocationEquipType::Loot, "common", "", 0, 0, 0,
          10
      )
{
}

MagicFragments::MagicFragments()
    : Item(
          "Magic Fragments", ItemLocationEquipType::Loot, "epic", "", 0, 0, 0,
          85
      )
{
}

DragonScale::DragonScale()
    : Item("Dragon Scale", ItemLocationEquipType::Loot, "epic", "", 0, 0, 0, 75)
{
}

DragonTooth::DragonTooth()
    : Item(
          "Dragon Tooth", ItemLocationEquipType::Loot, "legendary", "", 0, 0, 0,
          122
      )
{
}

AzeaelHead::AzeaelHead()
    : Item(
          "Azeael Head", ItemLocationEquipType::Loot, "legendary", "", 0, 0, 0,
          999999
      )
{
}
