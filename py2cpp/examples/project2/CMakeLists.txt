cmake_minimum_required(VERSION 3.14)
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

project(root2)
find_package(fmt REQUIRED)
add_executable(root2 main.cpp)
set_target_properties(root2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(root2 PUBLIC fmt::fmt)
target_include_directories(
  root2
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

enable_testing()
add_subdirectory(test)
