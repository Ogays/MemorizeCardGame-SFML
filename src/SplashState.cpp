/*
 * File:   SplashState.cpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <sstream>
#include <iostream>
#include "../include/SplashState.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/DEFINITION.hpp"

namespace Ogay {

    SplashState::SplashState(std::shared_ptr<GameData> data) : _data(data) {
    }

    void SplashState::Init() {
        _data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
    }

    void SplashState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();
        }
    }

    void SplashState::Update(float dt) {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
            _data->machine.AddState(std::unique_ptr<State>(new MainMenuState(_data)), true);
        }
    }

    void SplashState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }
}