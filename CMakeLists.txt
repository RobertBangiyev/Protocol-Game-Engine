cmake_minimum_required(VERSION 3.18)

project(my_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DPROTOCOL_WINDOWS)
elseif(APPLE)
	add_definitions(-DPROTOCOL_MAC)
elseif(UNIX)
	add_definitions(-DPROTOCOL_LINUX)
endif()

add_definitions(-DPROTOCOL_OPENGL)

add_subdirectory(MyGame)
add_subdirectory(Protocol)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)