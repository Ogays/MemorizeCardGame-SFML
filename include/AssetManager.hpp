#pragma once
/*
 * File:   AssetManager.hpp
 * Author: ogay
 *
 * Created on August 29, 2025, 9:36 AM
 */

#include <map>
#include <SFML/Graphics.hpp>

namespace Ogay {
    
    class AssetManager {
    public:
        AssetManager();
        ~AssetManager();
        
        void LoadTexture( std::string name, std::string fileName);
        sf::Texture &GetTexture( std::string name);
        
        void LoadFont( std::string name, std::string fileName);
        sf::Font &GetFont( std::string name);
        
        int face = 0;
		std::vector<int> array;
		std::string levelText;

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}