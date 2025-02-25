cmake_minimum_required(VERSION 3.26)

project(AlciaProject VERSION 1.0 DESCRIPTION "Alcia" LANGUAGES CXX)

# Set C++ standard to C++23
set(CMAKE_CXX_STANDARD 14)
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

# Link libraries if needed (e.g., for systems, frameworks)
# target_link_libraries(${PROJECT_NAME} PRIVATE some_library)

# Installation rules
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/ DESTINATION include FILES_MATCHING PATTERN "*.h")

# Cpack stuff
#include(InstallRequiredSystemLibraries)
#
#set(CPACK_PACKAGE_NAME "AlciaProject")
#set(CPACK_PACKAGE_VENDOR "Darleanow")
#set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Alcia - The official installer of the game.")
#set(CPACK_PACKAGE_VERSION "1.0")
#set(CPACK_PACKAGE_VERSION_MAJOR "1")
#set(CPACK_PACKAGE_VERSION_MINOR "0")
#set(CPACK_PACKAGE_VERSION_PATCH "0")
#set(CPACK_PACKAGE_INSTALL_DIRECTORY "AlciaProject ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
#set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/Readme.md")
#
## Specify the generator
#set(CPACK_GENERATOR "NSIS")
#
#include(CPack)
