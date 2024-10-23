//
// Created by joshb on 22/10/2024.
//

#include "je_Engine.h"

#include <SDL2/SDL_image.h>
#include <iostream>
#include <je_GameBase.h>
#include <ostream>

namespace jebEngine
{
    Engine::Engine()
    {
    }

    bool Engine::initialize(const char* t_title, int t_posX, int t_posY, int t_width, int t_height, bool t_fullscreen,
        GameBase* t_gameBase)
    {

        m_gameBase = t_gameBase;

        if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return false;
        }

        const int flags = t_fullscreen ? SDL_WINDOW_FULLSCREEN  : 0;
        m_window = SDL_CreateWindow(t_title, t_posX, t_posY, t_width, t_height, flags);
        if (!m_window) {
            SDL_Log("Unable to create window: %s", SDL_GetError());
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, 0);
        if (!m_renderer) {
            SDL_Log("Unable to create renderer: %s", SDL_GetError());
            return false;
        }

        if (IMG_Init(IMG_INIT_PNG) == 0)
        {
            SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
            return false;
        }

        m_gameBase->load(m_renderer);
        m_isRunning = true;
        return true;
    }

    void Engine::runLoop()
    {
        while(m_isRunning)
        {
            update();
            render();
        }
    }

    void Engine::handleEvents()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                m_isRunning = false;
            break;
            default:
                break;
        }
    }
}

