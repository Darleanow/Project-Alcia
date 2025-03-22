#pragma once

#include <map>
#include <memory>

class Item;

struct ItemRecipe
{
  std::map<std::shared_ptr<Item>, int> recipe;
};

template <typename T>
class CrafteableMixin
{
public:
  CrafteableMixin(ItemRecipe recipe) : m_recipe(std::move(recipe)) {};
  virtual ~CrafteableMixin();

  std::unique_ptr<T> craft()
  {
    return std::make_unique<T>(*this);
  }

  const ItemRecipe &get_recipe() const
  {
    return m_recipe;
  };

private:
  ItemRecipe m_recipe;
};
