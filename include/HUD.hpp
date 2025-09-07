#pragma once
/* 
 * File:   HUD.hpp
 * Author: ogay
 *
 * Created on August 29, 2025, 9:36 AM
 */

#include <SFML/Graphics.hpp>
#include "DEFINITION.hpp"
#include "Game.hpp"

namespace Ogay {
    
    class HUD {
    public:
        HUD(std::shared_ptr<GameData> data);
        
        void Draw();
        void UpdateText(std::string, int score);
        
    private:
        std::shared_ptr<GameData> _data;
        sf::Text _tickerText;
		sf::Text _scoreText;
    };
}