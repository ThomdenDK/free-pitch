add_library(states STATIC 
    state.cc 
    main_menu.cc
)

target_include_directories(states PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)