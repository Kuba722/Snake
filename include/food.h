#pragma once
#include<iostream>

/**
 * @class Food
 * @brief Represents the food item that the snake can consume.
 * 
 * This class manages the grid coordinates (X and Y) of the food piece,
 * handles random spawning on initialization, and provides safe setters
 * to prevent invalid positions.
 */
class Food{
    int x;  /**< The current X coordinate of the food on the grid. */
    int y;  /**< The current Y coordinate of the food on the grid. */

public:
    /**
     * @brief Default constructor that initializes the food at a random position.
     * 
     * Spawns the food within a default 10x10 grid area (0 to 9 for both X and Y)
     * using the pseudo-random number generator.
     */
    Food();
    
    /**
     * @brief Sets a new X coordinate for the food.
     * 
     * @param t_x The target X coordinate. Must be greater than or equal to 0.
     * @note If a negative value is passed, an error message is printed to std::cout 
     *       and the coordinate remains unchanged.
     */
    void setX(int t_x);

    /**
     * @brief Sets a new Y coordinate for the food.
     * 
     * @param t_y The target Y coordinate. Must be greater than or equal to 0.
     * @note If a negative value is passed, an error message is printed to std::cout 
     *       and the coordinate remains unchanged.
     */
    void setY(int t_y);
    
    /**
     * @brief Gets the current X coordinate of the food.
     * @return int The X position on the grid.
     */
    int getX() const;
    
    /**
     * @brief Gets the current Y coordinate of the food.
     * @return int The Y position on the grid.
     */
    int getY() const;
};