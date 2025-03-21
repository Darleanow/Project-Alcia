#pragma once

#include <memory>
#include <unordered_map>

class Item;

class ItemRegistry
{
public:
  static ItemRegistry &get()
  {
    static ItemRegistry registry;
    return registry;
  }

  void                  register_item(std::shared_ptr<Item> item);

  std::shared_ptr<Item> get_item(const std::string &name);

private:
  std::unordered_map<std::string, std::shared_ptr<Item>> m_items;
};
