add_library(core STATIC
    window/window.cc
    synth/synth.cc
    free_pitch/free_pitch.cc
)

add_subdirectory(states)
add_subdirectory(ui_elements)

target_link_libraries(core PRIVATE
    states
    ui_elements
)

target_include_directories(core PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
)