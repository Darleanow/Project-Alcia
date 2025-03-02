#pragma once
#include <string>

struct Range
{
  int begin;
  int end;
};

class UISystem
{
public:
  UISystem();
  ~UISystem();

  void greet() const;
  void display_rules() const;

  int  prompt_user_for_index_selection(
       const std::string &input_message, Range range
   );
};
