#pragma once

#include <any>
#include <memory>
#include <string>
#include <unordered_map>

class World;
class Hero;

class Action
{
public:
  Action(
      const std::string &id, const std::string &action_name,
      const std::string                        &action_description,
      std::unordered_map<std::string, std::any> results
  );
  ~Action();

  [[nodiscard]] std::string_view get_id() const;
  [[nodiscard]] std::string_view get_name() const;
  [[nodiscard]] std::string_view get_description() const;

  void execute(World &world, std::shared_ptr<Hero> player);

private:
  std::string                               m_id;
  std::string                               m_name;
  std::string                               m_description;
  std::unordered_map<std::string, std::any> m_results;
};
