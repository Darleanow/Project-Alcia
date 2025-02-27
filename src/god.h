#pragma once
#include "Item.h"
#include "Monster.h"

Monster *generate_monster(Hero *hero);

Item    *generate_item();

Item    *random_item(std::vector<Item *> items, std::vector<size_t> odds);
