#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

/**
 * @class AssetManager
 * @brief Singleton manager handling resource caching and lazy-loading for system assets.
 * 
 * This engine component serves as a centralized warehouse for heavyweight graphic assets 
 * (like typography fonts). By intercepting all allocation requests, it guarantees that 
 * identical external files are never read or stored twice in volatile memory, optimizing 
 * the hardware runtime footprint.
 */
class AssetManager {
private:
    
    /**
     * @brief Internal map associative dictionary matching file paths to instantiated font contexts.
     * 
     * Key is the string literal representing the file path location (e.g., "ARIALI.ttf"), 
     * while the value represents the operational sf::Font structure instance kept warm in cache.
     */
    std::map<std::string, sf::Font> fonts;

    /**
     * @brief Hidden default constructor.
     * 
     * Enforces the Singleton pattern design rules, safely disabling unauthorized 
     * external stack or heap-instantiated object initializations.
     */
    AssetManager() {} 

public:

    /**
     * @brief Retrieves the globally accessible thread-safe reference to the single Manager instance.
     * 
     * Leverages the Meyers Singleton paradigm approach (using a static local block variable) 
     * ensuring safe initialization timelines upon the first active call footprint.
     * 
     * @return AssetManager& Reference to the shared unique singleton instance.
     */
    static AssetManager& getInstance();

    /**
     * @brief Deleted copy constructor.
     * 
     * Explicitly prevents duplicating the asset manager system context reference wrapper across boundaries.
     */
    AssetManager(const AssetManager&) = delete;

    /**
     * @brief Deleted copy assignment operator.
     * 
     * Explicitly locks down value copying behaviors to protect the asset cache instance context.
     */
    void operator=(const AssetManager&) = delete;

    /**
     * @brief Retrieves a font asset from the memory cache, loading it from disk on-demand if missing.
     * 
     * Implements an intelligent flyweight caching pipeline (lazy-loading):
     * - Searches the internal repository map for the requested filename string.
     * - If found, immediately returns the warm memory reference.
     * - If missing, streams the target resource into memory via SFML's file loading system.
     * - In case of a missing file or system IO failure, spits an error log directly down to std::cerr.
     * 
     * @param filename The exact path descriptor or string key identifying the target file asset.
     * @return sf::Font& A live writable resource link pointing to the safely cached font structure.
     */
    sf::Font& getFont(const std::string& filename);
};