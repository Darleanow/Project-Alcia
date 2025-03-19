#include "ItemRegistry.h"
#include "_Item/Item.h"

void ItemRegistry::register_item(std::shared_ptr<Item> item)
{
  auto item_name     = item->get_name();
  m_items[item_name] = item;
}

std::shared_ptr<Item> ItemRegistry::get_item(const std::string &name)
{
  return m_items.count(name) ? m_items[name] : nullptr;
}
