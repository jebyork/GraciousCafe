set(ENGINE_SOURCES
        src/je_Engine.cpp
        src/je_GameBase.cpp)

include_directories(include)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

add_library(engine_lib STATIC ${ENGINE_SOURCES})

target_link_libraries(engine_lib PUBLIC
        SDL2::SDL2
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

target_include_directories(engine_lib PUBLIC include)