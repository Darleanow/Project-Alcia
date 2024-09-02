#pragma once
#include "Monster.h"
#include "Item.h"

Monster* generate_monster(Hero* hero);

Item* generate_item();

Item* random_item(std::vector<Item*> items, std::vector<size_t> odds);