add_library(Core STATIC)

target_sources(Core PRIVATE
  Action.cpp
  Location.cpp
  Parser.cpp
  World.cpp
  Equipment/Equipment.cpp
  Inventory/Inventory.cpp
  Stats/Stats.cpp
)

target_include_directories(Core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Core PRIVATE
  nlohmann_json::nlohmann_json
  Legacy
  UI
)
