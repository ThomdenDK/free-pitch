add_library(core STATIC
    window/window.cc
    synth/synth.cc
    initializer/initialize_free_pitch.cc
    free_pitch_impl/free_pitch_impl.cc
)

add_subdirectory(states)

target_link_libraries(core PRIVATE
    states
)