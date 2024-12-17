cmake_minimum_required(VERSION 3.26)
project(freepitch LANGUAGES CXX)

# Set the C++ standard and enable modules
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")

# Specify the executable
add_executable(${PROJECT_NAME} main.cpp)

set(SYSTEM_MODULES iostream)
set(SRC_MODULES FreePitch)

# Precompile system headers (like <iostream>) once
set(MODULES_DIR ${CMAKE_BINARY_DIR}/modules)
file(MAKE_DIRECTORY ${MODULES_DIR})

foreach(sys_mod SYSTEM_MODULES)   
add_custom_command(
    OUTPUT ${MODULES_DIR}/${sys_mod}.gcm
    COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header ${sys_mod} -o ${MODULES_DIR}/${sys_mod}.gcm
    COMMENT "Precompiling system modules"
)
endforeach()


add_custom_target(precompiled_modules DEPENDS ${MODULES_DIR}/iostream.gcm)

# Ensure the executable depends on precompiled modules
add_dependencies(${PROJECT_NAME} precompiled_modules)

# Include the directory with precompiled modules
target_include_directories(${PROJECT_NAME} PRIVATE ${MODULES_DIR})
target_sources(${PROJECT_NAME} PRIVATE FreePitch.cppm)
