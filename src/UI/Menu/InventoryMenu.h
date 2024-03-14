#pragma once

#include "AMenu.h"

#include "../../Hero.h"
#include <memory>

class InventoryMenu final : public AMenu
{
public:
  explicit InventoryMenu(std::shared_ptr<Hero> player);
  ~InventoryMenu() override = default;

  void execute() override;
  void draw_gui() const override;

private:
  std::shared_ptr<Hero> m_player;
};
