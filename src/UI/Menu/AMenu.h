#pragma once
#include "../../Hero.h"
#include <memory>

class AMenu
{
public:
  AMenu(const std::shared_ptr<Hero> &player) : m_player(player) {}
  virtual ~AMenu() noexcept = default;

  virtual void execute()        = 0;
  virtual void draw_gui() const = 0;

protected:
  std::shared_ptr<Hero> m_player;
};
