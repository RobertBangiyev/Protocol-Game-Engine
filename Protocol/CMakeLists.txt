set(SOURCE_FILES 
	ProtocolApp.cpp 
	GameWindow.cpp 
	GLFWimpl/GlfwImplementation.cpp
	Renderer.cpp
	Shader.cpp
	Sprite.cpp
	Events.cpp
	OpenGLimpl/OpenGLRenderer.cpp
	OpenGLimpl/OpenGLShader.cpp
	OpenGLimpl/OpenGLSprite.cpp
)

set(HEADER_FILES 
	Protocol.h 
	ProtocolApp.h 
	ProtocolUtils.h 
	WindowImplementation.h 
	GameWindow.h 
	GLFWimpl/GlfwImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Sprite.h
	SpriteImplementation.h
	Events.h
	KeyCodes.h
	OpenGLimpl/OpenGLRenderer.h
	OpenGLimpl/OpenGLShader.h
	OpenGLimpl/OpenGLSprite.h
)

add_library(protocol_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(protocol_lib PRIVATE pch.h)

add_definitions(-DPROTOCOL_LIB)

target_link_libraries(protocol_lib glfw glad stbi)

include_directories(../glfw/include)
include_directories(../Protocol)
include_directories(../glad/include)
include_directories(../stbi)