cmake_minimum_required(VERSION 3.24)
project(FreePitch)

set(CMAKE_CXX_STANDARD 20)

find_library(FLUIDSYNTH_LIBRARY NAMES fluidsynth)

add_executable(main main.cc free_pitch.cc single_notes.cc note.cc synth.cc)

target_link_libraries(main PRIVATE ${FLUIDSYNTH_LIBRARY})