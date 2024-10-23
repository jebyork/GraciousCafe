//
// Created by joshb on 22/10/2024.
//

#pragma once

struct SDL_Renderer;

namespace jebEngine
{
    class GameBase {
    public:
        virtual ~GameBase() = default;

        virtual void load(SDL_Renderer* t_Renderer);
        virtual void update(float t_deltaTime);
        virtual void draw();

    protected:

        SDL_Renderer* m_renderer = nullptr;
    };
}

