add_library(core STATIC
    initialize_free_pitch.cc
    window/window.cc
    synth/synth.cc
    free_pitch/free_pitch.cc
)

add_subdirectory(states)

target_link_libraries(core PRIVATE
    states
)

target_include_directories(core PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
)