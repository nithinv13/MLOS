# Start listing our other sub projects.
# See Also: dirs.proj
cmake_minimum_required(VERSION 3.9)
get_filename_component(MLOS_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
include("${MLOS_ROOT}/build/Mlos.Common.cmake")

add_subdirectory(SmartCache)
add_subdirectory(SmartSharedChannel)
