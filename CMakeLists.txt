cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_STANDARD 17)

project(main)

add_executable(main main.cpp)

add_subdirectory(externals/diatonic)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC externals/diatonic/include/
)

target_link_directories(
  ${PROJECT_NAME}
  PUBLIC externals/diatonic/src/
)

target_link_libraries(
  ${PROJECT_NAME}
  LINK_PUBLIC diatonic
)

# install(TARGETS main)