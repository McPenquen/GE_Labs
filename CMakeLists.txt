cmake_minimum_required(VERSION 3.11)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engineering)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

## Tile loader lib
file(GLOB_RECURSE SOURCE_FILES lib_tile_level_loader/*.cpp lib_tile_level_loader/*.h)
add_library(lib_tile_level_loader STATIC ${SOURCE_FILES})
target_include_directories(lib_tile_level_loader INTERFACE "${CMAKE_SOURCE_DIR}/lib_tile_level_loader/" )
target_link_libraries(lib_tile_level_loader lib_maths sfml-graphics)

# Maths lib
add_library(lib_maths INTERFACE)
target_sources(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths/maths.h")
target_include_directories(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths" SYSTEM INTERFACE ${SFML_INCS})

# ECM lib
file(GLOB_RECURSE SOURCE_FILES lib_ecm/*.cpp lib_ecm/*.h)
add_library(lib_ecm STATIC ${SOURCE_FILES})
target_include_directories(lib_ecm INTERFACE "${CMAKE_SOURCE_DIR}/lib_ecm" )
target_link_libraries(lib_ecm PRIVATE lib_maths)

#### TRY including res folder
include_directories(res)

## Practical 1
file(GLOB_RECURSE SOURCES 1_plain_main/*.cpp 1_plain_main/*.h)
add_executable(1_PLAIN_MAIN ${SOURCES})
target_include_directories(1_PLAIN_MAIN PRIVATE ${SFML_INCS})
target_link_libraries(1_PLAIN_MAIN sfml-graphics)

## Pong
file(GLOB_RECURSE SOURCES 2_pong/*.cpp 2_pong/*.h)
add_executable(2_PONG ${SOURCES} )
target_include_directories(2_PONG SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(2_PONG sfml-graphics)

## Space invaders
file(GLOB_RECURSE SOURCES 3_space_inv/*.cpp 3_space_inv/*.h)
add_executable(3_SPACE_INV ${SOURCES} )
target_include_directories(3_SPACE_INV SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(3_SPACE_INV sfml-graphics)

## Tile engine
file(GLOB_RECURSE SOURCES 4_tile_engine/*.cpp 4_tile_engine/*.h)
add_executable(4_TILE_ENGINE ${SOURCES} )
target_include_directories(4_TILE_ENGINE SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(4_TILE_ENGINE lib_maths lib_tile_level_loader sfml-graphics)

## Pac-man
file(GLOB_RECURSE SOURCES 5_pacman/*.cpp 5_pacman/*.h)
add_executable(5_PACMAN ${SOURCES} )
target_include_directories(5_PACMAN SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(5_PACMAN lib_ecm sfml-graphics)

