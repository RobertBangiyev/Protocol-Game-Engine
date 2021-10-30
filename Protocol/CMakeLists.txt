set(SOURCE_FILES ProtocolApp.cpp GameWindow.cpp GLFWimpl/GlfwImplementation.cpp)

set(HEADER_FILES Protocol.h ProtocolApp.h ProtocolUtils.h WindowImplementation.h GameWindow.h GLFWimpl/GlfwImplementation.h)

add_library(protocol_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(protocol_lib PRIVATE pch.h)

add_definitions(-DPROTOCOL_LIB)

target_link_libraries(protocol_lib glfw)

include_directories(../glfw/include)
include_directories(../Protocol)