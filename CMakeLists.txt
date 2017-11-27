cmake_minimum_required(VERSION 3.8)
project(CPP_herkansing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Source/Libs/Random.cpp Headers/Libs/Random.h Source/Libs/String.cpp Headers/Libs/String.h Source/Game.cpp Headers/Game.h Source/Models/Player.cpp Headers/Models/Player.h Source/State/Game_state.cpp Headers/State/Game_state.h Source/State/Main_state.cpp Headers/State/Main_state.h Source/Models/Sector.cpp Headers/Models/Sector.h Headers/Models/Package.h Source/Libs/Vector.cpp Headers/Libs/Vector.h Headers/Libs/CSV_reader.cpp Headers/Libs/CSV_reader.h Source/State/Game_state_context.cpp Headers/State/Game_state_context.h)
add_executable(CPP_herkansing ${SOURCE_FILES})

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")