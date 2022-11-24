cmake_minimum_required(VERSION 3.0)

# set the project name
project(main)

# set std = c++17
set(CMAKE_CXX_STANDARD 17)

# compiling optimisation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# add the executable
add_executable(main main.cc)

cmake_minimum_required(VERSION 3.0)