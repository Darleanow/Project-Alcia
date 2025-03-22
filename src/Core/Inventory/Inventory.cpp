#include "Inventory.h"

#include <algorithm>

void Inventory::remove_item(size_t index, int quantity)
{
  auto &stack = m_inventory.at(index);

  if(stack.quantity <= quantity) {
    m_inventory.erase(m_inventory.begin() + static_cast<int>(index));
  } else {
    stack.quantity -= quantity;
  }
}

std::optional<
    std::variant<std::shared_ptr<Item>, std::unique_ptr<GearInstance>>>
    Inventory::extract_item(size_t index)
{
  if(index >= m_inventory.size()) {
    return std::nullopt;
  }

  auto &stack = m_inventory[index];
  std::variant<std::shared_ptr<Item>, std::unique_ptr<GearInstance>> result;

  std::visit(
      [&](auto &ptr) {
        using PtrType = std::decay_t<decltype(ptr)>;

        if(stack.quantity <= 1) {
          result = std::move(ptr);
          m_inventory.erase(m_inventory.begin() + index);
          return;
        }

        if constexpr(std::is_same_v<PtrType, std::shared_ptr<Item>>) {
          result = std::shared_ptr<Item>(ptr);
        } else if constexpr(std::is_same_v<
                                PtrType, std::unique_ptr<GearInstance>>) {
          result = std::make_unique<GearInstance>(*ptr);
        }

        stack.quantity--;
      },
      stack.item
  );

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
