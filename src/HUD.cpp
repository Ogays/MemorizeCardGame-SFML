/* 
 * File:   HUD.cpp
 * Author: ogay
 * 
 * Created on August 29, 2025, 9:36 AM
 */

#include "../include/HUD.hpp"

namespace Ogay {

    HUD::HUD(std::shared_ptr<GameData> data) : _data(data) {
        _tickerText.setFont(_data->assets.GetFont("Flappy Font"));
        _tickerText.setCharacterSize(128);
        _tickerText.setFillColor(sf::Color::Red);
        _tickerText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2);

		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setCharacterSize(32);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setPosition(10.0f, 750.0f);
    }

    void HUD::Draw() {
        sf::Vector2f pos = _tickerText.getOrigin();
        _data->window.draw(_tickerText);
        _data->window.draw(_scoreText);
    }

    void HUD::UpdateText(std::string string, int score) {
        _tickerText.setString(string);
        _tickerText.setOrigin(_tickerText.getGlobalBounds().width / 2, _tickerText.getGlobalBounds().height / 2);

        _scoreText.setString("Score : " + std::to_string(score));
    }
}
