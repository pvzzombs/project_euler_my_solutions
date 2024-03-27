cmake_minimum_required(VERSION 3.5.0)

project(project_euler_my_solutions)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

function(add_cpp_file PROBLEM_NAME CPP_FILE_NAME)
  add_executable(${PROBLEM_NAME} ${CPP_FILE_NAME})
endfunction()

add_cpp_file(main src/main.cpp)
add_cpp_file(p001 src/p001.cpp)
add_cpp_file(p002 src/p002.cpp)
add_cpp_file(p003 src/p003.cpp)
add_cpp_file(p004 src/p004.cpp)
add_cpp_file(p005 src/p005.cpp)
add_cpp_file(p014 src/p014.cpp)
add_cpp_file(p015 src/p015.cpp)
