/*
 * File:   MainMenuState.cpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <sstream>
#include <iostream>
#include "../include/MainMenuState.hpp"
#include "../include/PlayState.hpp"
#include "../include/DEFINITION.hpp"

namespace Ogay {

    MainMenuState::MainMenuState(std::shared_ptr<GameData> data) : _data(data) {
    }

    void MainMenuState::Init() {
        _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_FILEPATH);
        //        _data->assets.LoadTexture("Next Button", BUTTON_NEXT_FILEPATH);
        _data->assets.LoadTexture("Easy Button", BUTTON_EASY_FILEPATH);
        _data->assets.LoadTexture("Medium Button", BUTTON_MEDIUM_FILEPATH);
        _data->assets.LoadTexture("Hard Button", BUTTON_HARD_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

        _buttonEasy.setTexture(this->_data->assets.GetTexture("Easy Button"));
        _buttonEasy.setPosition(148.0f, 330.0f);

        _buttonMedium.setTexture(this->_data->assets.GetTexture("Medium Button"));
        _buttonMedium.setPosition(148.0f, 430.0f);

        _buttonHard.setTexture(this->_data->assets.GetTexture("Hard Button"));
        _buttonHard.setPosition(148.0f, 530.0f);
    }

    void MainMenuState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();

            if (_data->input.IsSpriteClicked(_buttonEasy, sf::Mouse::Left, _data->window)) {
                _data->assets.face = EASY_FACE;
                _data->assets.array = EASY_ARRAY;
				_data->assets.levelText = "Easy";
                _data->machine.AddState(std::unique_ptr<State>(new PlayState(_data)), true);
            }

            if (_data->input.IsSpriteClicked(_buttonMedium, sf::Mouse::Left, _data->window)) {
                _data->assets.face = MEDIUM_FACE;
                _data->assets.array = MEDIUM_ARRAY;
                _data->assets.levelText = "Medium";
                _data->machine.AddState(std::unique_ptr<State>(new PlayState(_data)), true);
            }

            if (_data->input.IsSpriteClicked(_buttonHard, sf::Mouse::Left, _data->window)) {
                _data->assets.face = HARD_FACE;
                _data->assets.array = HARD_ARRAY;
                _data->assets.levelText = "Hard";
                _data->machine.AddState(std::unique_ptr<State>(new PlayState(_data)), true);
            }
        }
    }

    void MainMenuState::Update(float dt) {

    }

    void MainMenuState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_buttonEasy);
        _data->window.draw(_buttonMedium);
        _data->window.draw(_buttonHard);

        _data->window.display();
    }
}