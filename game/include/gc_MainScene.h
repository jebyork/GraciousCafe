//
// Created by joshb on 22/10/2024.
//
#pragma once
#include "je_GameBase.h"
namespace GCGame
{
    class MainScene : public jebEngine::GameBase{
    public:
        void load(SDL_Renderer* t_Renderer) override;
        void update(float t_deltaTime) override;
        void draw() override;
    };
}

