#include "World.h"
#include "../UI/Utils.h"

#include <iostream>

World::World(
    std::shared_ptr<Hero>                  player,
    std::vector<std::shared_ptr<Location>> locations
)
    : m_player(player),
      m_locations(std::move(locations)),
      m_current_location(m_locations.at(0))

{
}

World::~World() = default;

void World::display_actions_for_current_location()
{
  int index = 1;

  for(const auto &action : m_current_location.get()->get_location_actions()) {
    std::cout << index << ". " << action.get()->get_name() << std::endl;
    index++;
  }
}

void World::execute_action_at(size_t index)
{
  Utils::clear_screen();
  m_current_location->get_location_actions().at(--index)->execute(
      *this, m_player
  );
}

[[nodiscard]] size_t World::get_current_location_action_count() const
{
  return m_current_location->get_location_actions().size();
}

void World::set_location(const std::string &new_location)
{
  auto found_location = get_location_from_name(new_location);

  if(found_location) {
    m_current_location = std::move(found_location);
  }
}

std::shared_ptr<Location>
    World::get_location_from_name(const std::string &location_name)
{
  for(auto &location : m_locations) {
    if(location->get_location_name() == location_name) {
      return location;
    }
  }

  return nullptr;
}

std::shared_ptr<Hero> World::get_player()
{
  return m_player;
}
