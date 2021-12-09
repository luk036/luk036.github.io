project(root2Tests)
# find_package(doctest REQUIRED)
add_executable(root2Tests main.cpp test_root2.cpp)
set_target_properties(root2Tests PROPERTIES CXX_STANDARD 17)
# target_link_libraries(root2Tests PUBLIC fmt::fmt)
target_include_directories(
  root2Tests
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/../include>)

add_test(NAME Root2Tests COMMAND root2Tests)
