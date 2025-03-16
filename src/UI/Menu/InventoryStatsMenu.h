#pragma once

#include "AMenu.h"

class InventoryStatsMenu final : public AMenu
{
public:
  InventoryStatsMenu(const std::shared_ptr<Hero> player);
  ~InventoryStatsMenu() noexcept override = default;

  void execute() override;

private:
  void draw_gui() const override;
  void show_actions() const override;

  void equip_item();
  void unequip_item();
  void use_item();
  void throw_item();
};
