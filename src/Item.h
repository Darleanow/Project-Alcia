#pragma once
#include <random>
#include <string>
#include <vector>

class Item
{
private:
  int quantity = 0;

public:
  virtual std::string get_name () = 0;
  int                 get_quantity ();
  void                set_quantity (int amount);
  void                add_quantity (int amount = 1);
  virtual std::string get_type ()      = 0;
  virtual int         get_atk ()       = 0;
  virtual int         get_crit_rate () = 0;
  virtual std::string get_rarity ()    = 0;
  virtual std::string get_status ()    = 0;
  virtual int         get_price ()     = 0;
  virtual int         get_hp ()        = 0;
};

class Common_Sword : public Item
{
private:
  std::string name      = "Common Sword";
  std::string type      = "right_hand";
  std::string rarity    = "common";
  std::string status    = "0";
  int         atk       = 5;
  int         price     = 150;
  int         crit_rate = 10;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  int         get_atk () override;
  int         get_crit_rate () override;
  std::string get_rarity () override;
  std::string get_status () override;
  int         get_price () override;
  int         get_hp () override
  {
    return 0;
  }
};

class Rare_Sword : public Item
{
private:
  std::string name      = "Rare Sword";
  std::string type      = "right_hand";
  std::string rarity    = "rare";
  std::string status    = "0";
  int         atk       = 8;
  int         price     = 300;
  int         crit_rate = 15;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  int         get_atk () override;
  int         get_crit_rate () override;
  std::string get_rarity () override;
  std::string get_status () override;
  int         get_price () override;
  int         get_hp () override
  {
    return 0;
  }
};

class Epic_Sword : public Item
{
private:
  std::string name      = "Epic Sword";
  std::string type      = "right_hand";
  std::string rarity    = "epic";
  std::string status    = "0";
  int         atk       = 15;
  int         price     = 600;
  int         crit_rate = 20;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  int         get_atk () override;
  int         get_crit_rate () override;
  std::string get_rarity () override;
  std::string get_status () override;
  int         get_price () override;
  int         get_hp () override
  {
    return 0;
  }
};

class Legendary_Sword : public Common_Sword
{
private:
  std::string name      = "Legendary Sword";
  std::string type      = "right_hand";
  std::string rarity    = "legendary";
  std::string status    = set_status ();
  int         atk       = 35;
  int         price     = 15000;
  int         crit_rate = 20;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  int         get_atk () override;
  std::string get_rarity () override;
  int         get_crit_rate () override;
  std::string set_status ();
  std::string get_status () override;
  int         get_price () override;
  int         get_hp () override
  {
    return 0;
  }
};

class Common_Helmet : public Item
{
private:
  std::string name   = "Common Helmet";
  std::string type   = "helmet";
  std::string rarity = "common";
  int         hp     = 5;
  int         price  = 80;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Rare_Helmet : public Item
{
private:
  std::string name   = "Rare Helmet";
  std::string type   = "helmet";
  std::string rarity = "rare";
  int         hp     = 8;
  int         price  = 200;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Epic_Helmet : public Item
{
private:
  std::string name   = "Epic Helmet";
  std::string type   = "helmet";
  std::string rarity = "epic";
  int         hp     = 10;
  int         price  = 380;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Legendary_Helmet : public Item
{
private:
  std::string name   = "Legendary Helmet";
  std::string type   = "helmet";
  std::string rarity = "legendary";
  int         hp     = 15;

  int         price = 600;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Common_Chestplate : public Item
{
private:
  std::string name   = "Common Chestplate";
  std::string type   = "chestplate";
  std::string rarity = "common";
  int         hp     = 7;

  int         price = 80;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Rare_Chestplate : public Item
{
private:
  std::string name   = "Rare Chestplate";
  std::string type   = "chestplate";
  std::string rarity = "rare";
  int         hp     = 12;

  int         price = 200;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Epic_Chestplate : public Item
{
private:
  std::string name   = "Epic Chestplate";
  std::string type   = "chestplate";
  std::string rarity = "epic";
  int         hp     = 20;
  int         price  = 380;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Legendary_Chestplate : public Item
{
private:
  std::string name   = "Legendary Chestplate";
  std::string type   = "chestplate";
  std::string rarity = "legendary";
  int         hp     = 25;
  int         price  = 1000;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Common_Leggings : public Item
{
private:
  std::string name   = "Common Leggings";
  std::string type   = "leggings";
  std::string rarity = "common";
  int         hp     = 9;

  int         price = 80;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Rare_Leggings : public Item
{
private:
  std::string name   = "Rare Leggings";
  std::string type   = "leggings";
  std::string rarity = "rare";
  int         hp     = 11;
  int         price  = 200;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Epic_Leggings : public Item
{
private:
  std::string name   = "Epic Leggings";
  std::string type   = "leggings";
  std::string rarity = "epic";
  int         hp     = 17;
  int         price  = 380;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Legendary_Leggings : public Item
{
private:
  std::string name   = "Legendary Leggings";
  std::string type   = "leggings";
  std::string rarity = "legendary";
  int         hp     = 20;
  int         price  = 600;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Common_Boots : public Item
{
private:
  std::string name   = "Common Boots";
  std::string type   = "boots";
  std::string rarity = "common";
  int         hp     = 5;
  int         price  = 80;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Rare_Boots : public Item
{
private:
  std::string name   = "Rare Boots";
  std::string type   = "boots";
  std::string rarity = "rare";
  int         hp     = 8;
  int         price  = 200;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Epic_Boots : public Item
{
private:
  std::string name   = "Epic Boots";
  std::string type   = "boots";
  std::string rarity = "epic";
  int         hp     = 10;
  int         price  = 380;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class Legendary_Boots : public Item
{
private:
  std::string name   = "Legendary Boots";
  std::string type   = "boots";
  std::string rarity = "legendary";
  int         hp     = 15;
  int         price  = 600;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class health_potion : public Item
{
private:
  std::string name    = "Health Potion";
  std::string type    = "potion";
  std::string rarity  = "potion";
  int         hp_back = 15;
  int         price   = 50;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override;
  std::string get_rarity () override;
  int         get_price () override;
  int         get_hp () override;
  int         get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};
class strength_potion : public Item
{
private:
  std::string name      = "Strength Potion";
  std::string type      = "potion";
  std::string rarity    = "potion";
  int         given_atk = 15;
  int         price     = 120;

public:
  std::string get_name () override
  {
    return this->name;
  };
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  int get_hp () override
  {
    return 0;
  };
  int get_atk () override
  {
    return this->given_atk;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
};

class zombie_flesh : public Item
{
private:
  std::string name   = "Zombie flesh";
  std::string type   = "loot";
  std::string rarity = "common";
  int         price  = 2;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class zombie_eye : public Item
{
private:
  std::string name   = "Zombie eye";
  std::string type   = "loot";
  std::string rarity = "rare";
  int         price  = 10;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class bone_shard : public Item
{
private:
  std::string name   = "Bone shard";
  std::string type   = "loot";
  std::string rarity = "common";
  int         price  = 4;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class bones : public Item
{
private:
  std::string name   = "Bones";
  std::string type   = "loot";
  std::string rarity = "rare";
  int         price  = 15;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class troll_finger : public Item
{
private:
  std::string name   = "Troll finger";
  std::string type   = "loot";
  std::string rarity = "rare";
  int         price  = 25;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class empty_sack : public Item
{
private:
  std::string name   = "Empty sack";
  std::string type   = "loot";
  std::string rarity = "rare";
  int         price  = 20;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class troll_belt : public Item
{
private:
  std::string name   = "Old belt";
  std::string type   = "loot";
  std::string rarity = "epic";
  int         price  = 60;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class kobold_tails : public Item
{
private:
  std::string name   = "Kobold tail";
  std::string type   = "loot";
  std::string rarity = "rare";
  int         price  = 30;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class kobold_scepter : public Item
{
private:
  std::string name   = "Kobold Scepter";
  std::string type   = "loot";
  std::string rarity = "epic";
  int         price  = 64;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class oreade_powder : public Item
{
private:
  std::string name   = "Oreade powder";
  std::string type   = "loot";
  std::string rarity = "common";
  int         price  = 10;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class magic_fragments : public Item
{
private:
  std::string name   = "Magic fragment";
  std::string type   = "loot";
  std::string rarity = "epic";
  int         price  = 85;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class dragon_scale : public Item
{
private:
  std::string name   = "Dragon scale";
  std::string type   = "loot";
  std::string rarity = "epic";
  int         price  = 75;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class dragon_tooth : public Item
{
private:
  std::string name   = "Dragon tooth";
  std::string type   = "loot";
  std::string rarity = "legendary";
  int         price  = 122;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};

class azeael_head : public Item
{
private:
  std::string name   = "Azeael head";
  std::string type   = "loot";
  std::string rarity = "legendary";
  int         price  = 999999;

public:
  std::string get_type () override
  {
    return this->type;
  };
  std::string get_rarity () override
  {
    return this->rarity;
  };
  int get_price () override
  {
    return this->price;
  };
  std::string get_name () override
  {
    return this->name;
  }
  int get_atk () override
  {
    return 0;
  }
  int get_crit_rate () override
  {
    return 0;
  }
  std::string get_status () override
  {
    return "";
  }
  int get_hp () override
  {
    return 0;
  }
};
