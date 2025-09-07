#pragma once
/*
 * File:   Game.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "InputManager.hpp"
#include "AssetManager.hpp"

namespace Ogay {

    struct GameData {
        StateMachine machine;
        AssetManager assets;
        InputManager input;
        sf::RenderWindow window;
    };

    class Game {

    public:
        Game( int width, int height, std::string title);
        
    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;
        
        std::shared_ptr<GameData> _data = std::make_shared<GameData>();
        
        void Run();
    };
}