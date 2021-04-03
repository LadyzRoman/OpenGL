cmake_minimum_required(VERSION 3.17)
project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(OpenGL main.cpp)
target_link_libraries(OpenGL ${CONAN_LIBS})
set_target_properties(OpenGL PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")