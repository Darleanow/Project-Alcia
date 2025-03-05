#pragma once
#include "System/SysCall.h"
#include <cstdlib>

namespace Utils {
static inline void clear_screen()
{
  system("clear");
}

void   draw_box(int sx, int sy, int ex, int ey);

Coords get_terminal_size();
} // namespace Utils
