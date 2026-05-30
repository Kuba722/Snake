#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class Button
 * @brief An interactive user interface button component.
 * 
 * This class encapsulates a graphical rectangle and an integrated text label. 
 * It manages individual styling properties, coordinates pixel-accurate rendering bounds, 
 * and isolates hardware mouse click interactions using axis-aligned hitboxes.
 */
class Button{
    public:

    /**
     * @brief Configures the visual footprint, styling assets, and map coordinates for the button.
     * 
     * Initializes the geometric canvas:
     * - Configures the dimensions, fill colors, and a high-contrast boundary outline stroke.
     * - Shakes out anchor offsets by shifting the operational origin point (`setOrigin`) 
     *   directly to the absolute center of the box shape.
     * - Maps typography assets, computes approximate character scales based on structural 
     *   dimensions, and centers the visual text matrix dynamically over the bounding layout.
     * 
     * @param size Dimensional width and height bounding boxes expressed as a 2D float vector.
     * @param font Typography resource reference utilized to trace the character layers.
     * @param text String literal payload message printed over the button background area.
     * @param fillColor Base color theme applied to flush the internal canvas rectangle.
     * @param position Absolute screen coordinates where the center anchor node is placed.
     */
    void createButton(sf::Vector2f size, sf::Font& font, std::string text, sf::Color fillColor, sf::Vector2f position);

    /**
     * @brief Listens for hardware pointer actions to evaluate interactive triggers.
     * 
     * Captures the active mouse cursor tracking indexes relative to the window perimeter view. 
     * First verifies whether the coordinate layout intercepts the bounding box limits, 
     * then validates if the player executed a full click lifecycle release state match 
     * (`sf::Event::MouseButtonReleased`) utilizing the primary Left Mouse action key.
     * 
     * @param window Active system viewport canvas context tracking cursor constraints.
     * @param event Reference to the hardware input state packet currently parsed by the pipeline.
     * @return true The user successfully clicked and released the mouse over the button perimeter.
     * @return false No valid collision sequence or mouse interaction cycle matches were triggered.
     */
    bool actionListener(sf::RenderWindow& window, const sf::Event& event);

    /**
     * @brief Dispatches internal composite graphics directly to an active render buffer destination.
     * 
     * Draws individual visual primitives sequentially: flushes the background rectangle 
     * geometry base layer down into the raster pipeline first, then traces the label 
     * font overlay on top to preserve depth indexing.
     * 
     * @param target Render layout destination stream surface reference (e.g., sf::RenderWindow).
     */
    virtual void draw(sf::RenderTarget& target);

    private:

    sf::RectangleShape button;  /**< Structural rectangle shape handling background color layers and collision boundaries. */
    sf::Text btnText;   /**< String renderer layer detailing the action command assigned to this interface node. */
};