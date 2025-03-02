#include "Parser.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Parser::Parser() = default;

Parser::~Parser() = default;

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
          std::make_unique<Action>(name, description, results);

      actions.push_back(std::move(action));
    }

    std::string location_name = location_json["name"].get<std::string>();
    std::string location_description =
        location_json["description"].get<std::string>();

    std::shared_ptr<Location> location = std::make_shared<Location>(
        location_name, location_description, std::move(actions)
    );

    locations.push_back(std::move(location));
  }

  return locations;
}
