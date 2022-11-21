cmake_minimum_required(VERSION 3.0)
project(wikiracer)

# find_path(cpr_INCLUDE_DIR
#   NAMES cpr.h
#   PATH_SUFFIXES cpr
# )
# find_library(cpr_LIBRARY
#   NAMES cpr
#   )

# include(FindPackageHandleStandardArgs)
# find_package_handle_standard_args(cpr
#   FOUND_VAR cpr_FOUND
#   REQUIRED_VARS
#     cpr_LIBRARY
#     cpr_INCLUDE_DIR
# )
# if(cpr_FOUND AND NOT TARGET cpr::cpr)
#   add_library(cpr::cpr UNKNOWN IMPORTED)
#   set_target_properties(cpr::cpr PROPERTIES
#     IMPORTED_LOCATION "${cpr_LIBRARY}"
#     INTERFACE_INCLUDE_DIRECTORIES "${cpr_INCLUDE_DIR};${cpr_INCLUDE_DIR}/.."
#     )
#   message(STATUS "cpr include dir: ${cpr_INCLUDE_DIR}")
# endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(cpr CONFIG REQUIRED)

# adding all files
add_executable(main main.cpp wikiscraper.cpp.o error.cpp)

target_link_libraries(main PRIVATE cpr::cpr)
 