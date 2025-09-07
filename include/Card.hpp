#pragma once
/* 
 * File:   Card.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <SFML/Graphics.hpp>

namespace Ogay {
    
    class Card : private sf::Sprite {
    public:

        Card(sf::Texture &tex, sf::IntRect back, sf::IntRect front);
        bool IsOpen();
        void SetOpen(bool open);
        void SetPosition(sf::Vector2f pos);
        sf::Vector2f GetPosition();
        sf::FloatRect GetGlobalBound();
        void Render(sf::RenderWindow &window);
        void Animate();
        void SetID(int id);
        int GetID();
        sf::Sprite& GetSprite();

		bool IsActive();
		void Deactive();
        
    private:
        int _id{};
        bool _animate = false;
        sf::IntRect _front;
        sf::IntRect _back;
        bool _show;
        bool _open = false;
        int _frame;
        bool _isActive;
    };
}