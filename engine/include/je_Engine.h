//
// Created by joshb on 22/10/2024.
//

#pragma once
#include <SDL2/SDL.h>

namespace jebEngine
{
    class GameBase;

    class Engine {
    public:
        Engine();
        ~Engine();

        bool initialize(const char* t_title, int t_posX, int t_posY, int t_width, int t_height, bool t_fullscreen, GameBase* t_gameBase);
        void runLoop();
        void clean();

    private:

        void handleEvents();
        void update();
        void render();

        bool m_isRunning;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        GameBase* m_gameBase;
    };
}

