#pragma once
#include "Location.h"
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>

class Parser
{
public:
  Parser();
  ~Parser();

  std::ifstream  open_file(std::filesystem::path file_path);

  nlohmann::json stream_to_json(std::ifstream &file_stream);

  std::vector<std::shared_ptr<Location>>
      parse_locations(nlohmann::json json_content) const;

  // todo(Darleanow): Add parse for items there
};
