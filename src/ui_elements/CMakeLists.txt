add_library(ui_elements STATIC
    ui_button.cc
    ui_rect.cc
    ui_text.cc
    prop_to_pixel.cc
)

target_include_directories(ui_elements PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)