add_executable(my_game main.cpp)

target_link_libraries(my_game protocol_lib)

include_directories(../Protocol)