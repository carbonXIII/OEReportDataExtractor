cmake_minimum_required(VERSION 3.11)

project("Report data extractor" LANGUAGES C CXX)

find_package(OpenEnclave CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_executable(extractor extractor.cpp)

target_link_libraries(extractor openenclave::oehostapp)
