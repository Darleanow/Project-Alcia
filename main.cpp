#include "src/Core/Parser.h"
#include "src/Core/World.h"
#include "src/UI/UISystem.h"
#include "src/UI/Utils.h"

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

  Utils::clear_screen();

  UISystem user_interface;
  user_interface.greet();

  auto player = std::make_shared<Hero>();

  std::cout << "Tell me your name please..." << std::endl;
  std::cout << "name >";

  std::string temp_name;
  std::getline(std::cin, temp_name);
  player->set_name(temp_name);

  World world(player, std::move(locations));

  user_interface.display_rules();

  Utils::clear_screen();

  while(player->get_hp() > 0) {
    world.display_actions_for_current_location();
    size_t     option_count = world.get_current_location_action_count();
    Range      range {.begin = 1, .end = option_count};

    const auto input = user_interface.prompt_user_for_index_selection(
        "Select what to do", range
    );

    world.execute_action_at(static_cast<size_t>(input));
  }
}
