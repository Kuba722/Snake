#pragma once
#include <string>
#include <SFML/Graphics.hpp>


/**
 * @class Textbox
 * @brief An interactive UI element used to capture text input from the user.
 * 
 * This class renders a visual rectangular box along with the entered text. 
 * It manages its own focus state based on mouse clicks and safely filters 
 * keyboard events to handle basic alphanumeric entry, backspacing, and a visual cursor.
 */
class Textbox{

public:

    /**
     * @brief Configures and initializes the visual properties of the textbox.
     * 
     * Sets the box size, centers its origin, sets position, color, and configures 
     * the text overlay font, sizing, and default offset position.
     * 
     * @param size The width and height dimensions of the textbox bounding box.
     * @param position The center screen coordinates where the textbox will be placed.
     * @param font Reference to the loaded sf::Font to be applied to the text.
     * @param color The background fill color of the text input container rectangle.
     */
    void CreateTextbox(sf::Vector2f size, sf::Vector2f position, sf::Font& font, sf::Color color);

    /**
     * @brief Processes input events to handle focus and text modification.
     * 
     * Checks for mouse clicks to toggle the active focus state. If active, it listens 
     * for TextEntered events, filters out invalid/control keys (like Enter or Escape), 
     * manages Backspace deletion, and appends a temporary vertical pipe character "|" 
     * to act as a blinking cursor placeholder.
     * 
     * @param window Reference to the active window used to translate pixel mouse clicks to game coordinates.
     * @param event Reference to the current SFML event pulled from the main game loop.
     */
    void IsActive(sf::RenderWindow& window, const sf::Event& event);

    /**
     * @brief Renders the textbox rectangle and the typed string onto the screen.
     * 
     * @param window Reference to the window target where elements should be drawn.
     */
    void Draw(sf::RenderWindow& window);

    /**
     * @brief Retrieves the raw input string stored inside the textbox.
     * 
     * Pass an empty string by reference, and this method will populate it with 
     * the current text string without the trailing cursor character.
     * 
     * @param text Reference to a std::string where the output input value will be copied.
     */
    void GetText(std::string& text);

private:

    sf::RectangleShape textbox;     /**< The visual bounding box rectangle representing the input area. */
    sf::Text text;                  /**< The SFML graphical text object used to draw the string within the box. */

    bool active=false;              /**< Focus flag; true if the textbox is active and accepting keyboard inputs. */
    std::string input;              /**< Internal buffer string holding the raw characters typed by the player. */

};