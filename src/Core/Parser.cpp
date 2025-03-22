#include "Parser.h"
#include "CoreDefinitions.h"
#include "CoreUtils.h"
#include "Item/Gear/Gear.h"
#include "ItemRegistry/ItemRegistry.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

std::ifstream Parser::open_file(std::filesystem::path file_path)
{
  std::ifstream file_stream(file_path.c_str());

  if(!file_stream.is_open()) {
    throw std::runtime_error("Could not open file: " + file_path.string());
  }

  return file_stream;
}

nlohmann::json Parser::stream_to_json(std::ifstream &file_stream)
{
  nlohmann::json json;
  try {
    file_stream >> json;
  } catch(const nlohmann::json::parse_error &e) {
    std::cerr << "JSON parse error: " << e.what() << std::endl;
  }

  return json;
}

std::vector<std::shared_ptr<Location>>
    Parser::parse_locations(nlohmann::json json_content) const
{
  std::vector<std::shared_ptr<Location>> locations;

  for(const auto &location_json : json_content["locations"]) {
    std::vector<std::unique_ptr<Action>> actions;

    for(const auto &location_action_json : location_json["actions"]) {
      std::string id   = location_action_json["id"].get<std::string>();
      std::string name = location_action_json["name"].get<std::string>();
      std::string description =
          location_action_json["description"].get<std::string>();

      std::unordered_map<std::string, std::any> results;

      for(const auto &[key, value] : location_action_json["results"].items()) {
        if(value.is_boolean()) {
          results[key] = value.get<bool>();
        } else {
          results[key] = value.get<std::string>();
        }
      }

      std::unique_ptr<Action> action =
          std::make_unique<Action>(id, name, description, results);

      actions.push_back(std::move(action));
    }

    std::string location_id   = location_json["id"].get<std::string>();
    std::string location_name = location_json["name"].get<std::string>();
    std::string location_description =
        location_json["description"].get<std::string>();

    std::shared_ptr<Location> location = std::make_shared<Location>(
        location_id, location_name, location_description, std::move(actions)
    );

    locations.push_back(std::move(location));
  }

  return locations;
}

void Parser::parse_items(nlohmann::json json_content) const
{
  auto &item_registry = ItemRegistry::get();

  for(const auto &item_json : json_content["items"]) {
    std::optional<ItemType> item_type =
        CoreUtils::string_to_type(item_json["type"].get<std::string>());

    std::optional<Rarity> item_rarity =
        CoreUtils::string_to_rarity(item_json["rarity"].get<std::string>());

    if(!item_type.has_value()) {
      throw std::runtime_error(
          "Failed parsing the following object: " + item_json.dump()
      );
    }

    switch(item_type.value()) {
    case ItemType::Loot: {
      std::shared_ptr<Item> item = std::make_shared<Item>(
          item_json["name"], "", item_rarity, item_type.value(),
          item_json["obtained_from"].get<std::string>(),
          item_json["price"].get<int>()
      );
      item_registry.register_item(item);
      break;
    }
    case ItemType::Potion: {
      break;
    }
    case ItemType::Weapon:
    case ItemType::Armor: {
      ItemRecipe item_recipe;
      for(const auto &[name, quantity] : item_json["recipe"].items()) {
        std::shared_ptr<Item> item = item_registry.get_item(name);
        item_recipe.recipe[item]   = quantity;
      }

      std::optional<EquipmentLocation> equipment_location =
          CoreUtils::string_to_equipment_location(
              item_json["rarity"].get<std::string>()
          );

      if(!equipment_location.has_value()) {
        throw std::runtime_error("Gear doesn't have no valid EquipmentLocation"
        );
      }

      const auto           &stats_json = item_json["stats"];
      StatsValues           min_stats  = parse_stats_scaled(stats_json, 0.8f);
      StatsValues           max_stats  = parse_stats_scaled(stats_json, 1.2f);

      std::shared_ptr<Gear> gear = std::make_shared<Gear>(
          item_recipe, equipment_location.value(),
          item_json["name"].get<std::string>(), "", item_rarity,
          item_type.value(), item_json["price"].get<int>(), min_stats, max_stats
      );

      item_registry.register_item(gear);
      break;
    }
    }
  }
}

StatsValues Parser::parse_stats_scaled(
    const nlohmann::json &json_stats, float multiplier
) const
{
  StatsValues stats;

  for(const auto &[key, value] : json_stats.items()) {
    if(key == "health")
      stats.health = static_cast<int>(value.get<float>() * multiplier);
    else if(key == "max_health")
      stats.max_health = static_cast<int>(value.get<float>() * multiplier);
    else if(key == "attack")
      stats.attack = static_cast<int>(value.get<float>() * multiplier);
    else if(key == "defense")
      stats.defense = static_cast<int>(value.get<float>() * multiplier);
    else if(key == "crit_rate")
      stats.crit_rate = static_cast<int>(value.get<float>() * multiplier);
    else if(key == "crit_multiplier")
      stats.crit_multiplier = value.get<float>() * multiplier;
  }

  return stats;
}
