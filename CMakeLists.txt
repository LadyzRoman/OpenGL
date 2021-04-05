cmake_minimum_required(VERSION 3.17)
project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_SOURCE_DIR}/src)


add_executable(OpenGL src/main.cpp src/Shader.cpp src/Shader.h)
target_link_libraries(OpenGL ${CONAN_LIBS})
set_target_properties(OpenGL PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

file( COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )
file( COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )