#pragma once

#include "CoreDefinitions.h"
#include <string>

class Item
{
public:
  Item(std::string name, std::string description, Rarity rarity, int price);
  ~Item() noexcept = default;

  const std::string &get_name() const;
  const std::string &get_description() const;
  Rarity             get_rarity() const;
  int                get_price() const;

private:
  std::string m_name;
  std::string m_description;
  Rarity      m_rarity;
  int         m_price;
};
