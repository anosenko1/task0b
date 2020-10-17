cmake_minimum_required(VERSION 3.17)
project(task0b)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletests)

include_directories(lib/googletests/googletest/include)
add_executable(task0b main.cpp test.cpp FileReader.h FileReader.cpp TokenService.cpp TokenService.h ReportService.cpp ReportService.h WordStatService.cpp WordStatService.h)
target_link_libraries(task0b gtest)