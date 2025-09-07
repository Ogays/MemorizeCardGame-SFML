/* 
 * File:   Card.cpp
 * Author: ogay
 * 
 * Created on August 26, 2025, 9:06 AM
 */

#include "../include/Card.hpp"

namespace Ogay {

    Card::Card(sf::Texture& tex, sf::IntRect back, sf::IntRect front) {
        this->setTexture(tex);
        this->setOrigin(50.f, 80.f);
        _back = back;
        _front = front;
        _frame = 500;
        _show = true;
        _isActive = true;
    }

    bool Card::IsOpen() {
        return _open;
    }

    void Card::SetOpen(bool open) {
        if (open) {
            _open = true;
            this->setTextureRect(_front);
        } else {
            _open = false;
            this->setTextureRect(_back);
        }
    }

    void Card::SetPosition(sf::Vector2f pos) {
        this->setPosition(pos);
    }

    sf::Vector2f Card::GetPosition() {
        return this->getPosition();
    }

    sf::FloatRect Card::GetGlobalBound() {
        return this->getGlobalBounds();
    }

	//Scale card from 1 to 0 for closing animation
	//Scale card from 0 to 1 for opening animation
    void Card::Render(sf::RenderWindow& window) {
        this->setScale(_frame * 0.002f, 1.f);

        window.draw(*this);

        if (_animate) {
            _frame--;
            if (_frame <= 0) {
                _animate = false;
                _frame = 500;
                if (_open) {
                    this->SetOpen(false);
                } else {
                    this->SetOpen(true);
                }
            }
        }
    }

    void Card::Animate() {
        _frame = 500;
        _animate = true;
    }

	void Card::SetID(int id) {          // Set card face id
        _id = id;                       // ◯ = 1, ⬜ = 2, △ = 3, ⨯ = 4, ♦ = 5, ♥ = 6, ♣ = 7, ♠ = 8
    }

    int Card::GetID() {
        return _id;
    }

    sf::Sprite& Card::GetSprite() {
        return *this;
    }

	bool Card::IsActive() {         // Check if the card is active (can be clicked)
		return _isActive;           // True = active, False = inactive (already matched)
	}                               // True = can be rendered, False = cannot be rendered

	void Card::Deactive() {         // Set the card to inactive (already matched)
        _isActive = false;
	}
}