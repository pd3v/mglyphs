cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

set(DIATONIC_PATH externals/diatonic/)
message(${DIATONIC_PATH})
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

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  set(CMAKE_MACOSX_RPATH 1)
  set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "@loader_path/${DIATONIC_PATH}")
endif() 

#install(TARGETS main)