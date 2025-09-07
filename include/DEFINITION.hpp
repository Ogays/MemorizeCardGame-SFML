#pragma once
/*
 * File:   DEFINITION.hpp
 * Author: ogay
 *
 * Created on August 26, 2025, 9:06 AM
 */

#include <iostream>
#include <vector>

const int ScreenWidth = 520;
const int ScreenHeight = 800;

const float SPLASH_STATE_SHOW_TIME = 2.0f;
const std::string CARD                              = "res/image/card.png";
const std::string SPLASH_SCENE_BACKGROUND_FILEPATH  = "res/image/Splash.png";
const std::string MAIN_MENU_FILEPATH                = "res/image/Menu.png";

const std::string BUTTON_EASY_FILEPATH      = "res/image/easy.png";
const std::string BUTTON_MEDIUM_FILEPATH    = "res/image/medium.png";
const std::string BUTTON_HARD_FILEPATH      = "res/image/hard.png";

const std::string BUTTON_RETRY_FILEPATH = "res/image/retry.png";
const std::string BUTTON_BACK_FILEPATH  = "res/image/back.png";

const std::string FLAPPY_FONT_FILEPATH = "res/fonts/FlappyFont.ttf";

const std::string FLIPIN_SOUND_FILEPATH     = "res/sounds/flip-in.mp3";
const std::string FLIPOUT_SOUND_FILEPATH    = "res/sounds/flip-out.mp3";
const std::string PULLED_SOUND_FILEPATH     = "res/sounds/card-pulled.mp3";
const std::string THROW_SOUND_FILEPATH      = "res/sounds/card-throw.mp3";

enum class GameState {
    Welcome,
    Showing,
    Playing,
    Paused,
	GameOver
};

struct Guess {
	int ID;     // Card ID. ◯ = 1, ⬜ = 2, △ = 3, ⨯ = 4, ♦ = 5, ♥ = 6, ♣ = 7, ♠ = 8
	int SEQ;    // Card sequence in the vector
};

const std::vector<int> EASY_ARRAY   = { 1, 2, 3, 4, 1, 2, 3, 4 };                           // 4 pairs
const std::vector<int> MEDIUM_ARRAY = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6 };               // 6 pairs
const std::vector<int> HARD_ARRAY   = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 };   // 8 pairs

const int EASY_FACE = 5;    // Number of unique card faces. 4 faces + 1 back 
const int MEDIUM_FACE = 7;  // Number of unique card faces. 6 faces + 1 back 
const int HARD_FACE = 9;    // Number of unique card faces. 8 faces + 1 back 

const int MAX_SIZE = 9;     // Maximum number for array boundary