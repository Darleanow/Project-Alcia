#pragma once

#include "../Hero.h"
#include "Location.h"

class World
{
public:
  World(
      std::shared_ptr<Hero>                  player,
      std::vector<std::shared_ptr<Location>> locations
  );
  ~World();

  void                  display_actions_for_current_location();
  void                  execute_action_at(size_t index);
  [[nodiscard]] size_t  get_current_location_action_count() const;

  void                  set_location(const std::string &new_location);
  std::shared_ptr<Hero> get_player();

private:
  std::shared_ptr<Hero>                  m_player;
  std::vector<std::shared_ptr<Location>> m_locations;
  std::shared_ptr<Location>              m_current_location;

  std::shared_ptr<Location> get_location_from_id(const std::string &location_id
  );
};
