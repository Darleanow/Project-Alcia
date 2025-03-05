#pragma once
#include "Action.h"
#include <memory>
#include <string>
#include <string_view>
#include <vector>

class Location
{
public:
  Location(
      const std::string &id, const std::string &name,
      const std::string                   &description,
      std::vector<std::unique_ptr<Action>> actions
  );

  ~Location() = default;

  [[nodiscard]] std::string_view get_id() const;
  [[nodiscard]] std::string_view get_name() const;
  [[nodiscard]] std::string_view get_description() const;

  [[nodiscard]] const std::vector<std::unique_ptr<Action>> &
      get_location_actions() const;

private:
  std::string                          m_id;
  std::string                          m_name;
  std::string                          m_description;

  std::vector<std::unique_ptr<Action>> m_actions;
};
