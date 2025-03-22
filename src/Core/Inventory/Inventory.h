#pragma once

#include "Item/Gear/Instance/GearInstance.h"
#include "Item/Item.h"

#include <algorithm>
#include <memory>
#include <string>
#include <variant>
#include <vector>

template <typename T>
concept ValidInventoryType = std::is_same_v<T, std::shared_ptr<Item>> ||
                             std::is_same_v<T, std::unique_ptr<GearInstance>>;

struct ItemStack
{
  std::variant<std::shared_ptr<Item>, std::unique_ptr<GearInstance>> item;
  int                                                                quantity;
};

class Inventory
{
public:
  Inventory()  = default;
  ~Inventory() = default;

  template <ValidInventoryType T>
  void add_item(T item, int quantity = 1)
  {
    if(!item)
      return;

    std::string item_name = item->get_name();

    auto        it = std::find_if(
        m_inventory.begin(), m_inventory.end(),
        [&item_name](const ItemStack &stack) {
          return std::visit(
              [&item_name](auto &&ptr) {
                return ptr && ptr->get_name() == item_name;
              },
              stack.item
          );
        }
    );

    if(it != m_inventory.end()) {
      it->quantity += quantity;
    } else {
      m_inventory.emplace_back(ItemStack {std::move(item), quantity});
    }
  }

  void remove_item(size_t index, int quantity = 1);

  std::optional<
      std::variant<std::shared_ptr<Item>, std::unique_ptr<GearInstance>>>
                                extract_item(size_t index);

  size_t                        get_item_count() const;
  const std::vector<ItemStack> &get_items() const;

private:
  std::vector<ItemStack> m_inventory;
};
