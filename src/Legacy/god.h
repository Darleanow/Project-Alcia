#pragma once

#include "Item.h"
#include "Monster.h"

#include <memory>

Monster              *generate_monster(Hero *hero);

std::unique_ptr<Item> generate_item();

Item *random_item(std::vector<Item *> items, std::vector<size_t> odds);
