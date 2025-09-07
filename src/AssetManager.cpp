/*
 * File:   AssetManager.hpp
 * Author: ogay
 *
 * Created on August 29, 2025, 9:36 AM
 */

#include "../include/AssetManager.hpp"

namespace Ogay {

    AssetManager::AssetManager() : face(0) {
	}
	AssetManager::~AssetManager() {
	}
    
    void AssetManager::LoadTexture(std::string name, std::string fileName) {
        sf::Texture tex;
        if (tex.loadFromFile(fileName)) {
            this->_textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string name) {
        return this->_textures.at(name);
    }

    void AssetManager::LoadFont(std::string name, std::string fileName) {
        sf::Font font;
        if (font.loadFromFile(fileName)) {
            this->_fonts[name] = font;
        }
    }

    sf::Font &AssetManager::GetFont(std::string name) {
        return this->_fonts.at(name);
    }
}