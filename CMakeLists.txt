cmake_minimum_required(VERSION 3.9)
project(AlgoGit)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -o -save-temps")
set(CMAKE_SUPPRESS_REGENERATION true)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_executable(
	main
	Source_Files/source.cpp
	Source_Files/start.cpp)