set(SOURCE_FILES ProtocolApp.cpp)

set(HEADER_FILES Protocol.h ProtocolApp.h ProtocolUtils.h)

add_library(protocol_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_header(protocol_lib PRIVATE pch.h)