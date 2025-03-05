#pragma once

#include "../Core/Location.h"

#include <cstddef>

struct Range
{
  size_t begin;
  size_t end;
};

class UISystem
{
public:
  UISystem();
  ~UISystem();

  void greet() const;
  void display_rules() const;

  int  prompt_user_for_index_selection(Range range);

  void display_informations_of_current_location(
      std::shared_ptr<Location> location
  );

  void display_actions_for_current_location(std::shared_ptr<Location> location);
};
