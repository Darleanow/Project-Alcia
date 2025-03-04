#include "Action.h"
#include "../Hero.h"
#include "World.h"

#include <any>
#include <iostream>

Action::Action(
    const std::string &id, const std::string &action_name,
    const std::string                        &action_description,
    std::unordered_map<std::string, std::any> action_results
)
    : m_id(std::move(id)),
      m_name(std::move(action_name)),
      m_description(std::move(action_description)),
      m_results(std::move(action_results))
{
}

Action::~Action() = default;

std::string_view Action::get_id() const
{
  return m_id;
}

std::string_view Action::get_name() const
{
  return m_name;
}

std::string_view Action::get_description() const
{
  return m_description;
}

void Action::execute(World &world, std::shared_ptr<Hero> player)
{
  for(const auto &[key, value] : m_results) {
    if(key == "location_change") {
      try {
        const auto &location_name = std::any_cast<std::string>(value);
        world.set_location(location_name);
      } catch(const std::bad_any_cast &e) {
        std::cout << e.what() << '\n';
      }
    } else if(key == "trigger_encounter") {
      player->combat_main();
    } else if(key == "open_menu") {
    }
  }
}
