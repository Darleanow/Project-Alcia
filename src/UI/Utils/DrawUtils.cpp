#include "DrawUtils.h"
#include "System/SysCall.h"

#include <iostream>

struct BoxChars
{
  constexpr static const std::string_view h  = "═";
  constexpr static const std::string_view v  = "║";
  constexpr static const std::string_view tl = "╔";
  constexpr static const std::string_view tr = "╗";
  constexpr static const std::string_view bl = "╚";
  constexpr static const std::string_view br = "╝";
  constexpr static const std::string_view sr = "╣";
  constexpr static const std::string_view sl = "╠";
  constexpr static const std::string_view sm = "╬";
  constexpr static const std::string_view st = "╦";
  constexpr static const std::string_view sb = "╩";
};

static inline void set_cursor_pos(int x, int y)
{
  std::cout << "\033[" << y << ";" << x << "H";
}

void Utils::draw_box(int sx, int sy, int ex, int ey)
{

  for(int i = sx + 1; i <= ex - 1; i++) {
    set_cursor_pos(i, sy);
    std::cout << BoxChars::h;
  }

  for(int i = sy + 1; i <= ey - 1; i++) {
    set_cursor_pos(sx, i);
    std::cout << BoxChars::v;
    set_cursor_pos(ex, i);
    std::cout << BoxChars::v;
  }

  for(int i = sx + 1; i <= ex - 1; i++) {
    set_cursor_pos(i, ey);
    std::cout << BoxChars::h;
  }

  set_cursor_pos(sx, sy);
  std::cout << BoxChars::tl;

  set_cursor_pos(ex, sy);
  std::cout << BoxChars::tr;

  set_cursor_pos(sx, ey);
  std::cout << BoxChars::bl;

  set_cursor_pos(ex, ey);
  std::cout << BoxChars::br;
}

Coords Utils::get_terminal_size()
{
  return SysCalls::get_terminal_size();
}
