#pragma once

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
};
