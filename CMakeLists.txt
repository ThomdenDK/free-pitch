cmake_minimum_required(VERSION 3.24)
project(FreePitch)

set(CMAKE_CXX_STANDARD 20)

find_library(FLUIDSYNTH_LIBRARY NAMES fluidsynth)
find_library(SDL2_LIBRARY NAMES SDL2)
find_library(SDL2_TTF_LIBRARY NAMES SDL2_ttf)

add_executable(main main.cc)

add_subdirectory(src)

target_link_libraries(main PRIVATE 
    core
    ${FLUIDSYNTH_LIBRARY} 
    ${SDL2_LIBRARY}
    ${SDL2_TTF_LIBRARY}
)

target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
)