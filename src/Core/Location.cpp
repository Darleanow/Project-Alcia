#include "Location.h"

Location::Location(
    const std::string &id, const std::string &name,
    const std::string &description, std::vector<std::unique_ptr<Action>> actions
)
    : m_id(std::move(id)),
      m_name(std::move(name)),
      m_description(std::move(description)),
      m_actions(std::move(actions))
{
}

std::string_view Location::get_id() const
{
  return m_id;
}

std::string_view Location::get_name() const
{
  return m_name;
}

std::string_view Location::get_description() const
{
  return m_description;
}

const std::vector<std::unique_ptr<Action>> &
    Location::get_location_actions() const
{
  return m_actions;
}
