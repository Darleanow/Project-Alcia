#pragma once

#ifdef _WIN32
  #include <windows.h>
#else
  #include <sys/ioctl.h>
  #include <unistd.h>
#endif

struct Coords
{
  int x;
  int y;
};

namespace SysCalls {

static inline Coords get_terminal_size()
{
  int cols = 0, rows = 0;

#ifdef _WIN32
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  }

#else
  struct winsize w;
  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
    cols = w.ws_col;
    rows = w.ws_row;
  }
#endif

  return Coords {.x = cols, .y = rows};
}
} // namespace SysCalls
