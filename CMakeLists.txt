cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(DIATONIC_PATH externals/diatonic/)

project(main)

add_executable(main main.cpp)

add_subdirectory(${DIATONIC_PATH})

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC ${DIATONIC_PATH}include/
)

target_link_directories(
  ${PROJECT_NAME}
  PUBLIC ${DIATONIC_PATH}
)

target_link_libraries(
  ${PROJECT_NAME}
  LINK_PUBLIC diatonic
)

#install(TARGETS main)