#include "Item.h"
#include "Core/Stats/Stats.h"

Item::Item(
    const std::string &name, std::string type, const std::string &rarity,
    const std::string &status, int atk, int crit_rate, int hp, int price
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

std::string Item::get_type() const
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

StatsValues Item::get_stats() const
{
  return StatsValues(
      {.health     = get_hp(),
       .max_health = get_type() == "Potion" ? 0 : get_hp(),
       .attack     = get_atk(),
       .crit_rate  = get_crit_rate()}
  );
}

CommonSword::CommonSword()
    : Item("Common Sword", "Primary Hand", "common", "", 5, 10, 0, 150)
{
}

RareSword::RareSword()
    : Item("Rare Sword", "Primary Hand", "rare", "", 8, 15, 0, 300)
{
}

EpicSword::EpicSword()
    : Item("Epic Sword", "Primary Hand", "epic", "", 15, 20, 0, 600)
{
}

LegendarySword::LegendarySword()
    : Item(
          "Legendary Sword", "Primary Hand", "legendary", "Fire", 35, 20, 0,
          15000
      )
{
}

CommonHelmet::CommonHelmet()
    : Item("Common Helmet", "Helmet", "common", "", 0, 0, 5, 80)
{
}

RareHelmet::RareHelmet()
    : Item("Rare Helmet", "Helmet", "rare", "", 0, 0, 8, 200)
{
}

EpicHelmet::EpicHelmet()
    : Item("Epic Helmet", "Helmet", "epic", "", 0, 0, 10, 380)
{
}

LegendaryHelmet::LegendaryHelmet()
    : Item("Legendary Helmet", "Helmet", "legendary", "", 0, 0, 15, 600)
{
}

CommonChestplate::CommonChestplate()
    : Item("Common Chestplate", "Chestplate", "common", "", 0, 0, 7, 80)
{
}

RareChestplate::RareChestplate()
    : Item("Rare Chestplate", "Chestplate", "rare", "", 0, 0, 12, 200)
{
}

EpicChestplate::EpicChestplate()
    : Item("Epic Chestplate", "Chestplate", "epic", "", 0, 0, 20, 380)
{
}

LegendaryChestplate::LegendaryChestplate()
    : Item(
          "Legendary Chestplate", "Chestplate", "legendary", "", 0, 0, 25, 1000
      )
{
}

CommonLeggings::CommonLeggings()
    : Item("Common Leggings", "Leggings", "common", "", 0, 0, 9, 80)
{
}

RareLeggings::RareLeggings()
    : Item("Rare Leggings", "Leggings", "rare", "", 0, 0, 11, 200)
{
}

EpicLeggings::EpicLeggings()
    : Item("Epic Leggings", "Leggings", "epic", "", 0, 0, 17, 380)
{
}

LegendaryLeggings::LegendaryLeggings()
    : Item("Legendary Leggings", "Leggings", "legendary", "", 0, 0, 20, 600)
{
}

CommonBoots::CommonBoots()
    : Item("Common Boots", "Boots", "common", "", 0, 0, 5, 80)
{
}

RareBoots::RareBoots() : Item("Rare Boots", "Boots", "rare", "", 0, 0, 8, 200)
{
}

EpicBoots::EpicBoots() : Item("Epic Boots", "Boots", "epic", "", 0, 0, 10, 380)
{
}

LegendaryBoots::LegendaryBoots()
    : Item("Legendary Boots", "Boots", "legendary", "", 0, 0, 15, 600)
{
}

HealthPotion::HealthPotion()
    : Item("Health Potion", "Potion", "common", "", 0, 0, 15, 50)
{
}

StrengthPotion::StrengthPotion()
    : Item("Strength Potion", "Potion", "common", "", 15, 0, 0, 120)
{
}

ZombieFlesh::ZombieFlesh()
    : Item("Zombie Flesh", "Loot", "common", "", 0, 0, 0, 2)
{
}

ZombieEye::ZombieEye() : Item("Zombie Eye", "Loot", "rare", "", 0, 0, 0, 10) {}

BoneShard::BoneShard() : Item("Bone Shard", "Loot", "common", "", 0, 0, 0, 4) {}

Bones::Bones() : Item("Bones", "Loot", "rare", "", 0, 0, 0, 15) {}

TrollFinger::TrollFinger()
    : Item("Troll Finger", "Loot", "rare", "", 0, 0, 0, 25)
{
}

EmptySack::EmptySack() : Item("Empty Sack", "Loot", "rare", "", 0, 0, 0, 20) {}

TrollBelt::TrollBelt() : Item("Troll Belt", "Loot", "epic", "", 0, 0, 0, 60) {}

KoboldTails::KoboldTails()
    : Item("Kobold Tails", "Loot", "rare", "", 0, 0, 0, 30)
{
}

KoboldScepter::KoboldScepter()
    : Item("Kobold Scepter", "Loot", "epic", "", 0, 0, 0, 64)
{
}

OreadePowder::OreadePowder()
    : Item("Oreade Powder", "Loot", "common", "", 0, 0, 0, 10)
{
}

MagicFragments::MagicFragments()
    : Item("Magic Fragments", "Loot", "epic", "", 0, 0, 0, 85)
{
}

DragonScale::DragonScale()
    : Item("Dragon Scale", "Loot", "epic", "", 0, 0, 0, 75)
{
}

DragonTooth::DragonTooth()
    : Item("Dragon Tooth", "Loot", "legendary", "", 0, 0, 0, 122)
{
}

AzeaelHead::AzeaelHead()
    : Item("Azeael Head", "Loot", "legendary", "", 0, 0, 0, 999999)
{
}
