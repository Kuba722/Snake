#pragma once
#include "state.h"
#include "snake.h"
#include "food.h"
#include "map.h"
#include <SFML/Graphics.hpp>
#include <string>

/**
 * @class PlayState
 * @brief Manages the core gameplay loop of the Snake game.
 * 
 * This state handles live user input for snake steering, drives the game clock 
 * and movement delay, checks for collisions with walls or self, handles score tracking, 
 * and manages rendering of the checkered grass board, food, and snake elements.
 */
class PlayState : public State {
private:
    Snake snake;            /**< The snake engine object instance. */
    Food food;              /**< The food entity spawning logic and coordinate wrapper. */
    GameMap map;            /**< The configuration properties defining the grid boundaries. */

    char direction;         /**< Current active movement direction token: 'w', 's', 'a', or 'd'. */
    float delay;            /**< Time window constraint in seconds required between logical movement steps. */
    int margin;             /**< Grid rendering screen offset to frame the battlefield symmetrically. */
    int cellSize;           /**< Pixel scalar width/height representing a single grid unit area. */

    sf::Clock clock;        /**< Core delta timer tracking elapsed time slices for tick-based updates. */
    sf::Text player_txt;    /**< Graphical interface text displaying the player's profile name. */
    sf::Text score_txt;     /**< Graphical interface text displaying live gathered point summaries. */

    int s;                  /**< Inner tracker caching the score locally during this playthrough. */


public:

    /**
     * @brief Constructs the active gameplay environment state.
     * 
     * Sets initial variables (grid size, starting direction, speeds, margins),
     * prepares string overlays for the interface using the shared profile database, 
     * and maps typographic styles over text targets.
     * 
     * @param game Pointer to the main global game management framework.
     */
    PlayState(Game* game);

    /**
     * @brief Interprets active hardware keyboard inputs to queue direction changes.
     * 
     * Prevents self-crashing reversals (e.g., cannot turn directly Down 's' 
     * if the snake is currently moving Up 'w').
     * 
     * @param event Reference to the active SFML system event payload packet.
     */
    void handleEvents(sf::Event& event) override;

    /**
     * @brief Coordinates the periodic execution frame update tick.
     * 
     * Evaluates clock loops to advance snake placement positions at specific delays.
     * Checks if a food target has been harvested to grow the tail and update scores, 
     * and transitions execution context to EndState when fatal collisions occur.
     */
    void update() override;

    /**
     * @brief Combines layers into the output frame buffer for display.
     * 
     * Handles the sequential layout pipeline: background board grid rendering -> 
     * text layer generation -> food blitting -> body chain tracing -> head overlay highlighting.
     * Coordinates are converted from logic cells to pixels via formula: `(cell + margin) * cellSize`.
     * 
     * @param window Target rendering context window destination reference.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Renders a stylized checkered battlefield layout onto the screen space.
     * 
     * Cycles through the game map dimensions and alternates column shades 
     * between two tones of green depending on pixel modulo indexes.
     * 
     * @param window Target rendering context window destination reference.
     */
    void drawBoard(sf::RenderWindow& window);

    /**
     * @brief Evaluates environment positioning parameters for hazard impacts.
     * 
     * Validates if the head's current coordinates fall beyond the safe boundaries of the map 
     * or intersect with any index tracking the rest of the snake's body blocks.
     * 
     * @return true If a fatal collision occurred (triggering a Game Over condition).
     * @return false If the current space coordinates are safe.
     */
    bool collision();

    /**
     * @brief Binds consistent asset typography patterns and layouts across target UI texts.
     * 
     * Installs global shared font references, scales uniform text heights, assigns red 
     * palette accents, and stamps outline shadows to improve reading visibility above backgrounds.
     * 
     * @param text Reference to the targeted sf::Text element to format.
     */
    void txt_sett(sf::Text& text);
};