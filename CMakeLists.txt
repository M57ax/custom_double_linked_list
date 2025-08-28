cmake_minimum_required(VERSION 3.20)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()

add_library(aud STATIC
  list.cpp
)
target_include_directories(aud PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}  
)

add_executable(main
  main.cpp
)
target_link_libraries(main PRIVATE aud)

find_package(Catch2 3 REQUIRED)    
include(CTest)
include(Catch)

add_executable(tests
  test.cpp
)
target_link_libraries(tests PRIVATE
  aud
  Catch2::Catch2WithMain
)

catch_discover_tests(tests)
