#pragma once

#include "Location.h"
#include "Stats/Stats.h"

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

class Parser
{
public:
  Parser()  = default;
  ~Parser() = default;

  std::ifstream  open_file(std::filesystem::path file_path);

  nlohmann::json stream_to_json(std::ifstream &file_stream);

  std::vector<std::shared_ptr<Location>>
       parse_locations(nlohmann::json json_content) const;

  void parse_items(nlohmann::json json_content) const;

private:
  StatsValues parse_stats_scaled(
      const nlohmann::json &json_stats, float multiplier
  ) const;
};
