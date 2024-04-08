cmake_minimum_required(VERSION 3.5.0)

project(project_euler_my_solutions-problem025)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

function(add_cpp_file PROBLEM_NAME CPP_FILE_NAME)
  add_executable(${PROBLEM_NAME} ${CPP_FILE_NAME} ../mini-gmp/mini-gmp.c ../mini-gmp/mini-mpq.c)
  target_include_directories(${PROBLEM_NAME} PRIVATE ../../include)
endfunction()

add_cpp_file(solution025 p025.cpp)
