#pragma once

class AMenu
{
public:
  virtual ~AMenu() = default;

  virtual void execute()        = 0;
  virtual void draw_gui() const = 0;
};
