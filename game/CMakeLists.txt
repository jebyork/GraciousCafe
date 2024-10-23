set(GAME_SRCS
        main.cpp
        src/gc_MainScene.cpp)

include_directories(${CMAKE_SOURCE_DIR}/game/include)

add_executable(GAME ${GAME_SRCS})

target_include_directories(GAME PRIVATE ${CMAKE_SOURCE_DIR}/engine/include)
target_link_libraries(GAME engine_lib)