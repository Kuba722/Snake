#include "AssetManager.h"
#include <iostream>


AssetManager& AssetManager::getInstance() {
    static AssetManager instance; 
    return instance;
}

sf::Font& AssetManager::getFont(const std::string& filename) {

    auto& fontMap = getInstance().fonts;

    if (fontMap.find(filename) == fontMap.end()) {
        
        sf::Font font;
        if (font.loadFromFile(filename)) {
            fontMap[filename] = font;
        } else {
            std::cerr << "Error cannot open: " << filename << "\n";
        }
    }
    return fontMap[filename];
}