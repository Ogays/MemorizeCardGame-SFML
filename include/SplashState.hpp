#pragma once
/*
 * File:   SplashState.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Ogay {
    
    class SplashState : public State {
    public:
        SplashState(std::shared_ptr<GameData> data);
        
        void Init();
        
        void HandleInput();
        void Update( float dt );
        void Draw( float dt );
        
    private:
        std::shared_ptr<GameData> _data;
        
        sf::Clock _clock;
        sf::Sprite _background;
    };
}