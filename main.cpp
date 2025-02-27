#include "src/Hero.h"
#include "src/UI/UISystem.h"
#include "src/UI/Utils.h"

int main ()
{
  UISystem user_interface;
  Utils::clear_screen ();
  user_interface.greet ();

  Hero player;

  std::cout << "Tell me your name please . . ." << std::endl;
  std::cout << "name >";

  std::string temp_name;
  std::getline (std::cin, temp_name);
  player.set_name (temp_name);

  user_interface.display_rules ();

  Utils::clear_screen ();

  while (player.get_hp () > 0) {
    player.display_actions ();
  }
}
