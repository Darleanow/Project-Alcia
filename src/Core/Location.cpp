#include "Location.h"

Location::Location(
    const std::string &name, const std::string &description,
    std::vector<std::unique_ptr<Action>> actions
)
    : m_location_name(std::move(name)),
      m_location_description(std::move(description)),
      m_actions(std::move(actions))
{
}

Location::~Location() = default;

std::string_view Location::get_location_name() const
{
  return m_location_name;
}

std::string_view Location::get_location_description() const
{
  return m_location_description;
}

const std::vector<std::unique_ptr<Action>> &
    Location::get_location_actions() const
{
  return m_actions;
}
