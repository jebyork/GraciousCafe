//
// Created by joshb on 22/10/2024.
//

#include "gc_MainScene.h"

#include <iostream>
#include <ostream>

namespace GCGame
{
    void MainScene::load(SDL_Renderer* t_Renderer)
    {
        std::cout << "Loading Game Scene..." << std::endl;
    }

    void MainScene::update(float t_deltaTime)
    {
        std::cout << "Updating Game Scene..." << std::endl;
    }

    void MainScene::draw()
    {
        std::cout << "Drawing Game Scene..." << std::endl;
    }
}

