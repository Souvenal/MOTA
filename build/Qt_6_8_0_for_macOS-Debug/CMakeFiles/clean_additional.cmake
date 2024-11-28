# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MOTA_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MOTA_autogen.dir/ParseCache.txt"
  "MOTA_autogen"
  )
endif()
