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
  PUBLIC externals/diatonic/
)

target_link_libraries(
  ${PROJECT_NAME}
  LINK_PUBLIC diatonic
)

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(CMAKE_MACOSX_RPATH 1)
  set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "@loader_path/../lib")
endif() 

#install(TARGETS main)