#pragma once
/*
 * File:   GameOverState.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "PlayState.hpp"
#include "DEFINITION.hpp"

namespace Ogay {
	class GameOverState : public State {
	public:
		GameOverState(std::shared_ptr<GameData> data, int score, std::string level);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		std::shared_ptr<GameData> _data;
		
		sf::Sprite _retryButton;
		sf::Sprite _homeButton;

		sf::Text _scoreText;
		sf::Text _levelText;
		std::string _levelString;
		int _score{};


	};
}
