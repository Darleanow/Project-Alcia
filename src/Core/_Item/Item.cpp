#include "Item.h"

Item::Item(std::string name, std::string description, Rarity rarity, int price)
    : m_name(name),
      m_description(description),
      m_rarity(rarity),
      m_price(price)
{
}

const std::string &Item::get_name() const
{
  return m_name;
}

const std::string &Item::get_description() const
{
  return m_description;
}

Rarity Item::get_rarity() const
{
  return m_rarity;
}

int Item::get_price() const
{
  return m_price;
}
