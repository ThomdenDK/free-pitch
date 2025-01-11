add_subdirectory(states)
add_subdirectory(ui_elements)

find_package(SDL2)
find_package(SDL2_ttf)

add_library(windows STATIC window.cpp)
add_library(free_pitch STATIC free_pitch.cpp)
add_executable(main main.cpp)
target_link_libraries(states ui_elements)
target_link_libraries(windows SDL2 SDL2_ttf)
target_link_libraries(free_pitch states windows)
target_link_libraries(main free_pitch)