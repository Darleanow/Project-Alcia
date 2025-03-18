cmake_minimum_required(VERSION 3.26)

project(Alcia VERSION 1.0 DESCRIPTION "Alcia" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} 
  main.cpp 
  src/UI/Utils/DrawUtils.cpp
  src/UI/SystemRelated.cpp
  src/UI/UISystem.cpp
  src/god.cpp
  src/Hero.cpp
  src/Item.cpp
  src/Monster.cpp
  src/Core/Action.cpp
  src/Core/Location.cpp
  src/Core/Parser.cpp
  src/Core/World.cpp
  src/Core/Equipment/Equipment.cpp
  src/Core/Inventory/Inventory.cpp
  src/Core/Stats/Stats.cpp
  src/UI/Menu/InventoryStatsMenu.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SRC_DIR}/src)

target_compile_options( Alcia PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -Werror
  -Wshadow
  -Wnon-virtual-dtor
  -Wold-style-cast
  -Wcast-align
  -Wunused
  -Wconversion
  -Wsign-conversion
  -Wnull-dereference
  -Wdouble-promotion
  -Wimplicit-fallthrough
)

include(FetchContent) 

FetchContent_Declare(
  json 
  URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)

FetchContent_MakeAvailable(json)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE nlohmann_json::nlohmann_json
)

target_include_directories(${PROJECT_NAME} PRIVATE 
  ${CMAKE_BINARY_DIR}/_deps/json-src/include
)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/data/Locations.json
  ${CMAKE_CURRENT_BINARY_DIR}/data/Locations.json
  COPYONLY
)
