/*
 * File:   PlayState.cpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <iostream>
#include "../include/PlayState.hpp"
#include "../include/DEFINITION.hpp"
#include "../include/MainMenuState.hpp"
#include "../include/HUD.hpp"
#include "../include/GameOverState.hpp"

namespace Ogay {

    PlayState::PlayState(std::shared_ptr<GameData> data) : _data(data) {
    }

    void PlayState::Init() {
        if (!_flipInSoundBuffer.loadFromFile(FLIPIN_SOUND_FILEPATH)) {
            std::cout << "Error Loading Hit Sound Effect" << std::endl;
        }
        if (!_flipOutSoundBuffer.loadFromFile(FLIPOUT_SOUND_FILEPATH)) {
            std::cout << "Error Loading Wing Sound Effect" << std::endl;
        }
        if (!_throwSoundBuffer.loadFromFile(THROW_SOUND_FILEPATH)) {
            std::cout << "Error Loading Point Sound Effect" << std::endl;
        }
        if (!_pulledSoundBuffer.loadFromFile(PULLED_SOUND_FILEPATH)) {
            std::cout << "Error Loading Point Sound Effect" << std::endl;
        }

		_flipInSound.setBuffer(_flipInSoundBuffer);
		_flipOutSound.setBuffer(_flipOutSoundBuffer);
		_throwSound.setBuffer(_throwSoundBuffer);
		_pulledSound.setBuffer(_pulledSoundBuffer);

        _data->assets.LoadTexture("Card", CARD);

		std::vector<int> array = _data->assets.array;       //RANDOMIZED NUMBERS. 2 PAIRS
		_face = _data->assets.face;                         //NUMBER OF UNIQUE CARD FACES
		_size = array.size();                               //TOTAL NUMBER OF CARDS. EASY=8, MEDIUM=12, HARD=16
        _activeCard = _size;

        std::mt19937 generator(rd());
        std::shuffle(array.begin(), array.end(), generator);

        sf::IntRect back = sf::IntRect(0, 0, 100, 160); //BACK FACE
		sf::IntRect rect[MAX_SIZE];                     //FRONT FACE

        for (int i = 0; i < _face; i++) {
            rect[i] = sf::IntRect(i * 100, 0, 100, 160);
        }

        for (int i = 0; i < _size; i++) {
            sf::Vector2f pos;
            pos.x = (i % 4) * 120 + 80;
            pos.y = (i / 4) * 180 + 100;

            Card tmp(_data->assets.GetTexture("Card"), back, rect[array[i]]);
            tmp.SetPosition(pos);
            tmp.SetID(array[i]);
            tmp.SetOpen(false);
            _cardSprite.push_back(tmp);
        }

        _isReleased = true;
        _data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		_levelText = _data->assets.levelText;

        hud = new HUD(_data);
    }

    void PlayState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();

            if (event.type == sf::Event::MouseButtonReleased)
                _isReleased = true;

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (_isReleased == true) && (_state == GameState::Playing)) {
                _isReleased = false;
                for (int i = 0; i < _size; i++) {
                    sf::IntRect tempRect(_cardSprite[i].GetPosition().x - 50, _cardSprite[i].GetPosition().y - 80, 100, 160);
                    if (tempRect.contains(sf::Mouse::getPosition(_data->window)) && (!_cardSprite[i].IsOpen())) {
                        _opened++;
                        if (_opened == 1) {
                            _cardSprite[i].Animate();
							_flipInSound.play();
                            guess1.ID = _cardSprite[i].GetID();
                            guess1.SEQ = i;
                        }
                        if (_opened == 2) {
                            _cardSprite[i].Animate();
                            _flipInSound.play();
                            guess2.ID = _cardSprite[i].GetID();
                            guess2.SEQ = i;
                            _state = GameState::Paused;
                        }
                    }
                }
            }
        }
    }

    void PlayState::Update(float dt) {
        switch (_state) {
            case GameState::Welcome:
                _delta += dt;
                _readyText = "READY";

				if (_delta >= 3.5f) {                   // Pause for 3.5 seconds
                    for (int i = 0; i < _size; i++) {
                        _cardSprite[i].Animate();
                    }
                    _state = GameState::Showing;
					_throwSound.play();
                    _delta = 0;
                }
                break;

            case GameState::Showing:
                _delta += dt;
                _readyText = (std::to_string(static_cast<int>(_delta)));

				if (_delta >= 6.0f) {                   // Show cards for 6.0 seconds and then close all cards
                    _readyText = "";
                    for (int i = 0; i < _size; i++) {
                        _cardSprite[i].Animate();
                    }
                    _state = GameState::Playing;
                    _delta = 0;
                }
                break;

            case GameState::Playing:
                if (_opened == 2) {
					if (_cardSprite[guess1.SEQ].GetID() != _cardSprite[guess2.SEQ].GetID()) {  
                        _cardSprite[guess1.SEQ].Animate();
                        _cardSprite[guess2.SEQ].Animate();
						_flipOutSound.play();
						_score -= 5;
                    } else {
						_cardSprite[guess1.SEQ].Deactive();
						_cardSprite[guess2.SEQ].Deactive();
						_pulledSound.play();
						_activeCard -= 2;
						_grandScore = _grandScore + _score;
                        _score = 30;
                    }
                    _opened = 0;
                }
                break;

            case GameState::Paused:
                _delta += dt;
                if (_delta >= 1.00f) {
                    _state = GameState::Playing;
                    _delta = 0;
                }
                break;

			case GameState::GameOver:
                _delta += dt;
                if (_delta >= 2.00f) {
                    _data->machine.AddState(std::unique_ptr<State>(new GameOverState(_data, _grandScore, _levelText)), true);
                    _delta = 0;
                }
                break;

            default:
                break;
		}
    }

    void PlayState::Draw(float dt) {
        _data->window.clear();

		if (_activeCard > 0) {                              // If there are still active cards
            for (int i = 0; i < _size; i++) {
                if (_cardSprite[i].IsActive()) {
                    _cardSprite[i].Render(_data->window);
                }
            }
        } else {                                            // If all cards are matched
            _state = GameState::GameOver;
        }

        hud->UpdateText(_readyText, _grandScore);
        hud->Draw();
        _data->window.display();
    }
}