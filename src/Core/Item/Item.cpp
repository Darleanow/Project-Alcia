#include "Item.h"

Item::Item(
    std::string name, std::string description, Rarity rarity, ItemType type,
    int price, std::optional<std::string> obtained_from
)
    : m_name(name),
      m_description(description),
      m_rarity(rarity),
      m_item_type(type),
      m_obtained_from(obtained_from),
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

ItemType Item::get_type() const
{
  return m_item_type;
}

std::optional<std::string> Item::get_obtained_from() const
{
  return m_obtained_from;
}

int Item::get_price() const
{
  return m_price;
}
