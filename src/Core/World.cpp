#include "World.h"

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

void World::execute_action_at(size_t index)
{
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
  auto found_location = get_location_from_id(new_location);

  if(found_location) {
    m_current_location = std::move(found_location);
  }
}

std::shared_ptr<Location>
    World::get_location_from_id(const std::string &location_id)
{
  for(auto &location : m_locations) {
    if(location->get_id() == location_id) {
      return location;
    }
  }

  return nullptr;
}

const std::shared_ptr<Location> &World::get_current_location() const
{
  return m_current_location;
}

std::shared_ptr<Hero> World::get_player() const
{
  return m_player;
}
