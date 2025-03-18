add_library(UI STATIC)

target_sources(UI PRIVATE
  SystemRelated.cpp
  UISystem.cpp
  Menu/InventoryStatsMenu.cpp
  Utils/DrawUtils.cpp
)

target_link_libraries(UI PUBLIC
  Core Legacy
)

target_include_directories(UI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
