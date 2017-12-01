cmake_minimum_required(VERSION 3.8)
project(CPP_herkansing)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(SOURCE_FILES main.cpp Source/Libs/Random.cpp Headers/Libs/Random.h Source/Libs/String.cpp Headers/Libs/String.h Source/Game.cpp Headers/Game.h Source/Models/Player.cpp Headers/Models/Player.h Source/State/Game_state.cpp Headers/State/Game_state.h Source/State/HQ_state.cpp Headers/State/HQ_state.h Source/Models/Sector.cpp Headers/Models/Sector.h Headers/Models/Package.h Source/Libs/Vector.cpp Headers/Libs/Vector.h Headers/Libs/CSV_reader.cpp Headers/Libs/CSV_reader.h Source/State/Game_state_context.cpp Headers/State/Game_state_context.h Source/State/Sector_state.cpp Headers/State/Sector_state.h Source/Models/Sector_item.cpp Headers/Models/Sector_item.h Source/Models/Sector_empty.cpp Headers/Models/Sector_empty.h Source/Models/Sector_asteroide.cpp Headers/Models/Sector_asteroide.h Source/Models/Sector_ontmoeting.cpp Headers/Models/Sector_ontmoeting.h Source/Models/Sector_planeet.cpp Headers/Models/Sector_planeet.h Source/Models/Sector_ship.cpp Headers/Models/Sector_ship.h)
add_executable(CPP_herkansing ${SOURCE_FILES} Source/Models/Sector_ontmoeting.cpp Headers/Models/Sector_ontmoeting.h Source/Models/Sector_planeet.cpp Headers/Models/Sector_planeet.h Source/Models/Sector_ship.cpp Headers/Models/Sector_ship.h)

