#pragma once
#include "AMenu.h"
#include <functional>
#include <unordered_map>

class InventoryStatsMenu final : public AMenu
{
public:
  explicit InventoryStatsMenu(const std::shared_ptr<Hero> &player);
  ~InventoryStatsMenu() noexcept override = default;
  void execute() override;

private:
  void draw_gui() const override;
  void show_actions() const override;

  void handle_user_selection(int selection);

  void equip_item();
  void unequip_item();
  void use_item();
  void throw_item();

  using ActionHandler = std::function<void()>;
  std::unordered_map<int, ActionHandler> actions_;

  void                                   initialize_actions();

  void show_equippable_items(std::vector<size_t> &indices) const;
  void show_useable_items(std::vector<size_t> &indices) const;
  void show_equipped_items(std::vector<EquipmentLocation> &locations) const;
};
