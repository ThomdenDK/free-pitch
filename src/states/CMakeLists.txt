add_library(states STATIC 
    state.cpp
    main_menu.cpp
    minigame_menu.cpp
)

target_include_directories(states PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)