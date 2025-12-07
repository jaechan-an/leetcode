cmake_minimum_required(VERSION 3.21)

project(leetcode VERSION 1.0.0)

configure_file(LeetcodeConfig.h.in LeetcodeConfig.h)

include(CTest)

# C++ settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Options for libraries
option(USE_LEETCODE "Use the Leetcode library" ON)
option(USE_GOOGLE_TEST "Use GoogleTest for testing" ON)

# Project library
if(USE_LEETCODE)
  add_subdirectory(problem)
  list(APPEND EXTRA_LIBS problem)
endif()

# GoogleTest
if(USE_GOOGLE_TEST)
  add_subdirectory(test)
endif()

add_executable(${CMAKE_PROJECT_NAME} main.cc)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}"
)

