#pragma once

#include <string>

class Item
{
public:
  Item(std::string name, std::string description, int price);
  ~Item() noexcept = default;

  const std::string &get_name() const;
  const std::string &get_description() const;
  int                get_price() const;

private:
  std::string m_name;
  std::string m_description;
  int         m_price;
};
