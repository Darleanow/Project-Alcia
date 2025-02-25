cmake_minimum_required(VERSION 3.26)

project(AlciaProject VERSION 1.0 DESCRIPTION "Alcia" LANGUAGES CXX)

# Set C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the output directories for build files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Glob for source and header files in the src directory
file(GLOB_RECURSE ALCIA_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
file(GLOB_RECURSE ALCIA_HEADERS
    ${PROJECT_SOURCE_DIR}/src/*.h
)

# Add executable target including the main.cpp in the root directory
add_executable(${PROJECT_NAME} main.cpp ${ALCIA_SOURCES} ${ALCIA_HEADERS})

# Organize sources into groups for IDEs
source_group(TREE ${PROJECT_SOURCE_DIR}/src PREFIX "Source Files" FILES ${ALCIA_SOURCES})
source_group(TREE ${PROJECT_SOURCE_DIR}/src PREFIX "Header Files" FILES ${ALCIA_HEADERS})

# Enable warnings and other compilation options
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive- /Zc:preprocessor /Zc:__cplusplus)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

include(FetchContent)

FetchContent_Declare(
  SQLiteCpp
  GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp
  GIT_TAG master
)

FetchContent_Declare(
  sqlite3
  GIT_REPOSITORY https://github.com/sqlite/sqlite.git 
  GIT_TAG master
)

FetchContent_MakeAvailable(sqlite3 SQLiteCpp)

# Link the libraries correctly
target_link_libraries(${PROJECT_NAME} 
  PRIVATE SQLiteCpp sqlite3 pthread dl
)

# Ensure headers are included
target_include_directories(${PROJECT_NAME} PRIVATE 
  ${CMAKE_BINARY_DIR}/_deps/sqlitecpp-src/include
  ${CMAKE_BINARY_DIR}/_deps/sqlite3-src
)
