#pragma once
/*
 * File:   InputManager.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */


#include <SFML/Graphics.hpp>

namespace Ogay {
    
    class InputManager {
    public:
        InputManager() {}
        ~InputManager() {}
        
        bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition( sf::RenderWindow &window);
    };
}