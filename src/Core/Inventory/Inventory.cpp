#include "Inventory.h"
#include <algorithm>

void Inventory::add_item(std::unique_ptr<Item> item, int quantity)
{
  if(!item)
    return;

  std::string item_name = item->get_name();

  auto        it = std::find_if(
      m_inventory.begin(), m_inventory.end(),
      [&item_name](const ItemStack &stack) {
        return stack.item->get_name() == item_name;
      }
  );

  if(it != m_inventory.end()) {
    it->quantity += quantity;
  } else {
    m_inventory.emplace_back(ItemStack {std::move(item), quantity});
  }
}

void Inventory::remove_item(size_t index, int quantity)
{
  if(m_inventory.at(index).quantity <= quantity) {
    m_inventory.erase(m_inventory.begin() + static_cast<int>(index));
  } else {
    m_inventory.at(index).quantity -= quantity;
  }
}

std::unique_ptr<Item> Inventory::extract_item(size_t index)
{
  if(index >= m_inventory.size()) {
    return nullptr;
  }

  auto                 &stack = m_inventory[index];

  std::unique_ptr<Item> result = nullptr;

  if(stack.quantity <= 1) {
    result = std::move(stack.item);
    m_inventory.erase(m_inventory.begin() + static_cast<int>(index));
  } else {
    auto factory = [](const Item &original) -> std::unique_ptr<Item> {
      return std::make_unique<Item>(original);
    };

    try {
      result = factory(*stack.item);
      stack.quantity--;
    } catch(const std::exception &) {
      stack.quantity--;
    }
  }

  return result;
}

size_t Inventory::get_item_count() const
{
  return m_inventory.size();
}

const std::vector<ItemStack> &Inventory::get_items() const
{
  return m_inventory;
}
