#include "Parser.h"
#include "UISystem.h"
#include "Utils/DrawUtils.h"
#include "World.h"

#include <filesystem>
#include <iostream>

int main()

{

  Utils::clear_screen();

  Parser                parser;

  std::filesystem::path locations_path("./data/Locations.json");
  std::filesystem::path items_path("./data/Items.json");

  std::ifstream         locations_file = parser.open_file(locations_path);
  std::ifstream         items_file     = parser.open_file(items_path);

  nlohmann::json        locations_json = parser.stream_to_json(locations_file);
  nlohmann::json        items_json     = parser.stream_to_json(items_file);

  auto                  locations = parser.parse_locations(locations_json);
  parser.parse_items(items_json);

  UISystem user_interface;
  user_interface.greet();

  std::cout << "What's your name?\n";
  std::cout << ">";

  std::string player_name;
  std::getline(std::cin, player_name);

  auto  player = std::make_shared<Hero>(player_name);
  World world(player, std::move(locations));

  user_interface.display_rules();

  player->m_inventory->add_item(std::make_unique<EpicSword>());
  player->m_inventory->add_item(std::make_unique<CommonChestplate>());
  player->m_inventory->add_item(std::make_unique<CommonHelmet>());
  player->m_inventory->add_item(std::make_unique<HealthPotion>(), 2);

  while(player->m_stats->is_alive()) {

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
