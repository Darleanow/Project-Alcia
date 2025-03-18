add_library(Legacy STATIC)

target_sources(Legacy PRIVATE
    god.cpp
    Hero.cpp
    Item.cpp
    Monster.cpp
)

target_include_directories(Legacy PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Legacy PRIVATE
  Core
  UI
)
