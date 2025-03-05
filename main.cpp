#include "src/Core/Parser.h"
#include "src/Core/World.h"
#include "src/UI/SystemRelated.h"
#include "src/UI/UISystem.h"
#include "src/UI/Utils/DrawUtils.h"

#include <filesystem>
#include <iostream>

int main()

{

  Utils::clear_screen();

  Parser                parser;
  std::filesystem::path path("./data/Locations.json");
  std::ifstream         file      = parser.open_file(path);
  nlohmann::json        json      = parser.stream_to_json(file);
  auto                  locations = parser.parse_locations(json);

  UISystem              user_interface;
  user_interface.greet();

  std::cout << "What's your name?\n";
  std::cout << ">";

  std::string player_name;
  std::getline(std::cin, player_name);

  auto  player = std::make_shared<Hero>(player_name);
  World world(player, std::move(locations));

  user_interface.display_rules();

  while(player->get_hp() > 0) {

    user_interface.display_informations_of_current_location(
        world.get_current_location()
    );
    user_interface.display_actions_for_current_location(
        world.get_current_location()
    );
    size_t     option_count = world.get_current_location_action_count();
    Range      range {.begin = 1, .end = option_count};

    const auto input = user_interface.prompt_user_for_index_selection(range);

    world.execute_action_at(static_cast<size_t>(input));
  }

  Utils::clear_screen();

  std::cout << color(ColorType::RED) << "Game Over!"
            << color(ColorType::DEFAULT) << std::endl;

  std::cout << "Thanks for playing Project: Alcia!" << std::endl;

  return 0;
}
