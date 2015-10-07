cmake_minimum_required (VERSION 2.6)
project (MyProject)

file (GLOB_RECURSE source . *.cpp)

foreach (src ${source})
  get_filename_component ( name ${src} NAME_WE )
  add_executable(${name} ${src})
endforeach(src ${source})
