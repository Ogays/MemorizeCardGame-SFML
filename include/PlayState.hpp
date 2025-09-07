#pragma once
/*
 * File:   PlayState.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <algorithm> // for std::shuffle
#include <random>    // for std::random_device and std::mt19937
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Card.hpp"
#include "HUD.hpp"
#include "DEFINITION.hpp"

namespace Ogay {

    class PlayState : public State {
    public:
        PlayState(std::shared_ptr<GameData> data);

        void Init();

        void HandleInput();
        void Update( float dt );
        void Draw( float dt );

    private:
        std::shared_ptr<GameData> _data;

        int _size{};
        int _face{};
		int _activeCard{};

        float _delta = 0;
        Guess guess1{};
        Guess guess2{};
        GameState _state = GameState::Welcome;
        HUD *hud = nullptr;

        std::random_device rd;
        std::string _readyText;
		std::string _levelText;
        
        sf::Sprite _card;
        std::vector<Card> _cardSprite;
        int _opened = 0;
		int _grandScore = 0;
        int _score = 30;
        bool _isReleased = false;

        sf::SoundBuffer _flipInSoundBuffer;
        sf::SoundBuffer _flipOutSoundBuffer;
        sf::SoundBuffer _throwSoundBuffer;
        sf::SoundBuffer _pulledSoundBuffer;

        sf::Sound _flipInSound;
        sf::Sound _flipOutSound;
        sf::Sound _throwSound;
        sf::Sound _pulledSound;
    };
}