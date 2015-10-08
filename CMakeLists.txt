cmake_minimum_required (VERSION 2.6)
project (MyProject)

include_directories ("include" "src" ".")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file (GLOB_RECURSE source . ./src/*.cpp)
file (GLOB_RECURSE source_include . ./include/*.cpp)

foreach (src ${source})
  get_filename_component ( name ${src} NAME_WE )
  add_executable(${name} ${src} ${source_include})
endforeach(src ${source})
