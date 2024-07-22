cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

option(GIT_ACTION FALSE)
option(BUILD_17 TRUE)

if(APPLE AND NOT GIT_ACTION)
  if(BUILD_17)
    set(CMAKE_C_COMPILER /opt/local/libexec/llvm-10/bin/clang)
    set(CMAKE_CXX_COMPILER /opt/local/libexec/llvm-10/bin/clang++)
  else()  
    set(CMAKE_C_COMPILER /usr/bin/clang)
    set(CMAKE_CXX_COMPILER /usr/bin/clang++)
  endif(BUILD_17)
endif()

set(DIATONIC_PATH externals/diatonic/)

project(mglyphs)

add_executable(${PROJECT_NAME} main.cpp)

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
	#LINK_PUBLIC diatonic
	diatonic
)

install(TARGETS ${PROJECT_NAME})
