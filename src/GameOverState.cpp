/*
 * File:   GameOverState.cpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include "../include/GameOverState.hpp"

namespace Ogay {

	GameOverState::GameOverState(std::shared_ptr<GameData> data, int score, std::string level) : _data(data), _score(score), _levelString(level){
	}

	void GameOverState::Init() {
		_data->assets.LoadTexture("Back Button", BUTTON_BACK_FILEPATH);
		_data->assets.LoadTexture("Retry Button", BUTTON_RETRY_FILEPATH);

		_homeButton.setTexture(_data->assets.GetTexture("Back Button"));
		_homeButton.setPosition(50.0f, 400.0f);

		_retryButton.setTexture(_data->assets.GetTexture("Retry Button"));
		_retryButton.setPosition(300.0f, 400.0f);

		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		std::string scoreString = "Score : " + std::to_string(_score);
		_scoreText.setString(scoreString);
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2.0f, _scoreText.getGlobalBounds().height / 2.0f);
		_scoreText.setPosition(_data->window.getSize().x / 2.0f, _data->window.getSize().y - 500.0f);

		_levelText.setFont(_data->assets.GetFont("Flappy Font"));
		_levelText.setString("Level : " + _levelString);
		_levelText.setCharacterSize(56);
		_levelText.setFillColor(sf::Color::White);
		_levelText.setOrigin(_levelText.getGlobalBounds().width / 2.0f, _levelText.getGlobalBounds().height / 2.0f);
		_levelText.setPosition(_data->window.getSize().x / 2.0f, _data->window.getSize().y - 600.0f);
	}

	void GameOverState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
				_data->machine.AddState(std::unique_ptr<State>(new PlayState(_data)), true);
			}

			if (_data->input.IsSpriteClicked(_homeButton, sf::Mouse::Left, _data->window)) {
				_data->machine.AddState(std::unique_ptr<State>(new MainMenuState(_data)), true);
			}

		}
	}

	void GameOverState::Update(float dt) {
	}

	void GameOverState::Draw(float dt) {
		_data->window.clear(sf::Color::Black);
		_data->window.draw(_homeButton);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);
		_data->window.draw(_levelText);
		_data->window.display();
	}
}