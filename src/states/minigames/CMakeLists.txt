add_library(minigames STATIC 
    single_notes.cc 
    note.cc
)

target_include_directories(minigames PUBLIC
    ${CMAKE_SOURCE_DIR}
)