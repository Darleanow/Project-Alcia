#pragma once

#include "CoreDefinitions.h"
#include <optional>
#include <string>

class Item
{
public:
  Item(
      std::string name, std::string description, Rarity rarity, ItemType type,
      int price, std::optional<std::string> obtained_from = std::nullopt
  );
  ~Item() noexcept = default;

  const std::string         &get_name() const;
  const std::string         &get_description() const;
  Rarity                     get_rarity() const;
  ItemType                   get_type() const;
  std::optional<std::string> get_obtained_from() const;
  int                        get_price() const;

private:
  std::string                m_name;
  std::string                m_description;
  ItemType                   m_item_type;
  Rarity                     m_rarity;
  std::optional<std::string> m_obtained_from;
  int                        m_price;
};
