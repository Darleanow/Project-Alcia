#pragma once

#include "../../Item.h"
#include <memory>
#include <vector>

struct ItemStack
{
  std::unique_ptr<Item> item;
  int                   quantity;
};

class Inventory
{
public:
  Inventory()  = default;
  ~Inventory() = default;

  void                  add_item(std::unique_ptr<Item> item, int quantity = 1);
  void                  remove_item(size_t index, int quantity = 1);
  std::unique_ptr<Item> extract_item(size_t index);
  size_t                get_item_count() const;
  const std::vector<ItemStack> &get_items() const;

private:
  std::vector<ItemStack> m_inventory;
};
