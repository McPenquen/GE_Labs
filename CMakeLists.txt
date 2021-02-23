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
target_link_libraries(4_TILE_ENGINE sfml-graphics)