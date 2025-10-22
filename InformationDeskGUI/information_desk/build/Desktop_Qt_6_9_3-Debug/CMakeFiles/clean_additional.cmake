# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/information_desk_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/information_desk_autogen.dir/ParseCache.txt"
  "information_desk_autogen"
  )
endif()
