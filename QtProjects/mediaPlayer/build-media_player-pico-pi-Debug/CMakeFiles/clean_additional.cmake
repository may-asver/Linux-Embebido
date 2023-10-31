# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/media_player_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/media_player_autogen.dir/ParseCache.txt"
  "media_player_autogen"
  )
endif()
