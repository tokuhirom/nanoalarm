cmake_minimum_required (VERSION 2.6)
project(nanoalarm)

enable_testing()

add_executable(01_simple t/01_simple.cc)
set_target_properties(01_simple PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/t/")

add_test(NAME prove COMMAND prove t)

include_directories(extlib/)
