#include "Item.h"

Item::Item(std::string name, std::string description, int price)
    : m_name(name),
      m_description(description),
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

int Item::get_price() const
{
  return m_price;
}
