#include "Item.h"

int Item::get_quantity ()
{
  return this->quantity;
}

void Item::set_quantity (int amount)
{
  this->quantity = amount;
}

void Item::add_quantity (int amount)
{
  this->quantity += amount;
}

std::string Common_Sword::get_type ()
{
  return this->type;
}

int Common_Sword::get_atk ()
{
  return this->atk;
}

int Common_Sword::get_crit_rate ()
{
  return this->crit_rate;
}

std::string Common_Sword::get_rarity ()
{
  return this->rarity;
}

std::string Common_Sword::get_status ()
{
  return this->status;
}

int Common_Sword::get_price ()
{
  return this->price;
}

std::string Rare_Sword::get_type ()
{
  return this->type;
}

int Rare_Sword::get_atk ()
{
  return this->atk;
}

int Rare_Sword::get_crit_rate ()
{
  return this->crit_rate;
}

std::string Rare_Sword::get_rarity ()
{
  return this->rarity;
}

std::string Rare_Sword::get_status ()
{
  return this->status;
}

int Rare_Sword::get_price ()
{
  return this->price;
}

std::string Epic_Sword::get_type ()
{
  return this->type;
}

int Epic_Sword::get_atk ()
{
  return this->atk;
}

int Epic_Sword::get_crit_rate ()
{
  return this->crit_rate;
}

std::string Epic_Sword::get_rarity ()
{
  return this->rarity;
}

std::string Epic_Sword::get_status ()
{
  return this->status;
}

int Epic_Sword::get_price ()
{
  return this->price;
}

int Legendary_Sword::get_atk ()
{
  return this->atk;
}

int Legendary_Sword::get_crit_rate ()
{
  return this->crit_rate;
}

int Legendary_Sword::get_price ()
{
  return this->price;
}

std::string Legendary_Sword::get_rarity ()
{
  return this->rarity;
}

std::string Legendary_Sword::get_type ()
{
  return this->type;
}

std::string Legendary_Sword::set_status ()
{
  std::vector<std::string> status = {
      "Poison", "Fire", "Ice", "Haunted", "Nature"
  };
  std::mt19937        gen (std::random_device {}());
  std::vector<double> chances {10, 10, 10, 10, 10};
  // size_t is suitable for indexing.
  std::discrete_distribution<std::size_t> d {chances.begin (), chances.end ()};

  std::string                             chosen_status = status[d (gen)];

  return chosen_status;
}

std::string Legendary_Sword::get_status ()
{
  return this->status;
}

int Common_Helmet::get_hp ()
{
  return this->hp;
}

int Common_Helmet::get_price ()
{
  return this->price;
}

std::string Common_Helmet::get_rarity ()
{
  return this->rarity;
}

std::string Common_Helmet::get_type ()
{
  return this->type;
}

int Rare_Helmet::get_hp ()
{
  return this->hp;
}

int Rare_Helmet::get_price ()
{
  return this->price;
}

std::string Rare_Helmet::get_rarity ()
{
  return this->rarity;
}

std::string Rare_Helmet::get_type ()
{
  return this->type;
}

int Epic_Helmet::get_hp ()
{
  return this->hp;
}

int Epic_Helmet::get_price ()
{
  return this->price;
}

std::string Epic_Helmet::get_rarity ()
{
  return this->rarity;
}

std::string Epic_Helmet::get_type ()
{
  return this->type;
}

int Legendary_Helmet::get_hp ()
{
  return this->hp;
}

int Legendary_Helmet::get_price ()
{
  return this->price;
}

std::string Legendary_Helmet::get_rarity ()
{
  return this->rarity;
}

std::string Legendary_Helmet::get_type ()
{
  return this->type;
}

int Common_Chestplate::get_hp ()
{
  return this->hp;
}

int Common_Chestplate::get_price ()
{
  return this->price;
}

std::string Common_Chestplate::get_rarity ()
{
  return this->rarity;
}

std::string Common_Chestplate::get_type ()
{
  return this->type;
}

int Rare_Chestplate::get_hp ()
{
  return this->hp;
}

int Rare_Chestplate::get_price ()
{
  return this->price;
}

std::string Rare_Chestplate::get_rarity ()
{
  return this->rarity;
}

std::string Rare_Chestplate::get_type ()
{
  return this->type;
}

int Epic_Chestplate::get_hp ()
{
  return this->hp;
}

int Epic_Chestplate::get_price ()
{
  return this->price;
}

std::string Epic_Chestplate::get_rarity ()
{
  return this->rarity;
}

std::string Epic_Chestplate::get_type ()
{
  return this->type;
}

int Legendary_Chestplate::get_hp ()
{
  return this->hp;
}

int Legendary_Chestplate::get_price ()
{
  return this->price;
}

std::string Legendary_Chestplate::get_rarity ()
{
  return this->rarity;
}

std::string Legendary_Chestplate::get_type ()
{
  return this->type;
}

int Common_Leggings::get_hp ()
{
  return this->hp;
}

int Common_Leggings::get_price ()
{
  return this->price;
}

std::string Common_Leggings::get_rarity ()
{
  return this->rarity;
}

std::string Common_Leggings::get_type ()
{
  return this->type;
}

int Rare_Leggings::get_hp ()
{
  return this->hp;
}

int Rare_Leggings::get_price ()
{
  return this->price;
}

std::string Rare_Leggings::get_rarity ()
{
  return this->rarity;
}

std::string Rare_Leggings::get_type ()
{
  return this->type;
}

int Epic_Leggings::get_hp ()
{
  return this->hp;
}

int Epic_Leggings::get_price ()
{
  return this->price;
}

std::string Epic_Leggings::get_rarity ()
{
  return this->rarity;
}

std::string Epic_Leggings::get_type ()
{
  return this->type;
}

int Legendary_Leggings::get_hp ()
{
  return this->hp;
}

int Legendary_Leggings::get_price ()
{
  return this->price;
}

std::string Legendary_Leggings::get_rarity ()
{
  return this->rarity;
}

std::string Legendary_Leggings::get_type ()
{
  return this->type;
}

int Common_Boots::get_hp ()
{
  return this->hp;
}

int Common_Boots::get_price ()
{
  return this->price;
}

std::string Common_Boots::get_rarity ()
{
  return this->rarity;
}

std::string Common_Boots::get_type ()
{
  return this->type;
}

int Rare_Boots::get_hp ()
{
  return this->hp;
}

int Rare_Boots::get_price ()
{
  return this->price;
}

std::string Rare_Boots::get_rarity ()
{
  return this->rarity;
}

std::string Rare_Boots::get_type ()
{
  return this->type;
}

int Epic_Boots::get_hp ()
{
  return this->hp;
}

int Epic_Boots::get_price ()
{
  return this->price;
}

std::string Epic_Boots::get_rarity ()
{
  return this->rarity;
}

std::string Epic_Boots::get_type ()
{
  return this->type;
}

int Legendary_Boots::get_hp ()
{
  return this->hp;
}

int Legendary_Boots::get_price ()
{
  return this->price;
}

std::string Legendary_Boots::get_rarity ()
{
  return this->rarity;
}

std::string Legendary_Boots::get_type ()
{
  return this->type;
}

int health_potion::get_hp ()
{
  return this->hp_back;
}

int health_potion::get_price ()
{
  return this->price;
}

std::string health_potion::get_rarity ()
{
  return this->rarity;
}

std::string health_potion::get_type ()
{
  return this->type;
}
