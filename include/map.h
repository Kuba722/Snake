#pragma once

/**
 * @class GameMap
 * @brief Defines the logical grid boundaries of the snake gameplay arena.
 * 
 * This class stores the dimensional scale (width and height) of the playing field.
 * It is used by the game collision systems to verify boundary constraints and by
 * the rendering algorithms to scale the checkered background grid accurately.
 */
class GameMap{
public:

    int width;  /**< The total number of logical grid tiles along the horizontal axis. */
    int height; /**< The total number of logical grid tiles along the vertical axis. */

    /**
     * @brief Constructs a GameMap object with custom grid dimensions.
     * 
     * @param w The desired layout width quantified in tile counts.
     * @param h The desired layout height quantified in tile counts.
     */
    GameMap(int w, int h);

    /**
     * @brief Retrieves the maximum horizontal tile span of the active arena grid.
     * @return int The width boundary limit.
     */
    int getWidth();

    /**
     * @brief Retrieves the maximum vertical tile span of the active arena grid.
     * @return int The height boundary limit.
     */
    int getHeight();
};