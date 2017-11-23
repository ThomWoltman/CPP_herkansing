cmake_minimum_required(VERSION 3.8)
project(CPP_herkansing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Source/Libs/Random.cpp Headers/Libs/Random.h Source/Libs/String.cpp Headers/Libs/String.h Source/Game.cpp Headers/Game.h Source/Models/Player.cpp Headers/Models/Player.h Source/State/Game_state.cpp Headers/State/Game_state.h Source/State/Main_state.cpp Headers/State/Main_state.h)
add_executable(CPP_herkansing ${SOURCE_FILES})

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")