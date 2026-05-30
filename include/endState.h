#pragma once
#include "state.h"
#include "button.h"
#include "game.h"
#include "playState.h"
#include "menuState.h"
#include <fstream>

/**
 * @class EndState
 * @brief Handles the screen displayed immediately after a Game Over trigger occurs.
 * 
 * This state processes the endgame summary layout. It freeze-frames the player's 
 * final performance results, automatically verifies and persists potential high-scores 
 * into local storage, and serves menu buttons for restarting or backing out to the main menu hub.
 */
class EndState : public State {
private:
    sf::Text player_txt;    /**< UI text wrapper displaying the current player's profile name. */
    sf::Text score_txt;     /**< UI text wrapper displaying the final points accumulated during the run. */
    sf::Text over_txt;      /**< UI text header block displaying the stylized "GAME OVER" alarm string. */
    Button play_again_bnt;  /**< Navigation trigger resetting points to zero and initializing a clean PlayState. */
    Button menu_bnt;        /**< Navigation trigger to jump directly back to the main startup hub (MenuState). */


public:

    /**
     * @brief Constructs the Game Over end-of-lifecycle state context.
     * 
     * Hooks into the centralized AssetManager system to map lookups for typographical fonts, 
     * builds geometry limits and anchor nodes for interactive buttons, extracts state metrics 
     * from the runtime context, and automatically invokes the secure save sequence pipeline.
     * 
     * @param game Pointer to the main global game management framework lifecycle driver.
     */
    EndState(Game* game);

    /**
     * @brief Evaluates hardware interface events to track menu traversal choices.
     * 
     * Intercepts pointing click actions over action layers. If "PLAY AGAIN" triggers, 
     * score tracking registers are zeroed out before pushing a hot-reload of PlayState. 
     * If "MENU" fires, it routes execution backwards to the core landing screen.
     * 
     * @param event Reference to the active SFML system event interaction packet.
     */
    void handleEvents(sf::Event& event) override;

    /**
     * @brief Updates internal layout parameters or dynamic visual frame properties.
     * 
     * @note This layout acts entirely as a static utility frame responding to discrete user actions, 
     *       leaving this method intentionally empty.
     */
    void update() override;

    /**
     * @brief Draws summary fields and state button matrices onto the render buffer.
     * 
     * Clears and blits graphics assets in ordered passes: navigation button components 
     * are printed first, followed by text elements (Score, Name, Game Over alerts) laid on top.
     * 
     * @param window Target rendering context window destination reference.
     */
    void render(sf::RenderWindow& window)override;
    
    /**
     * @brief Binds uniform formatting and aesthetic assets across target UI texts.
     * 
     * Standardizes graphic metrics on target references: forces character heights to 40pt, 
     * injects a red core canvas color fill, and traces a distinct yellow high-contrast 
     * outline frame to separate letters from dark backgrounds.
     * 
     * @param text Reference to the targeted sf::Text element to format.
     */
    void txt_sett(sf::Text& text);

    /**
     * @brief Evaluates, sorts, and flushes session performance scores to persistent storage.
     * 
     * Executes the ranking updates business logic:
     * - Searches the cache for matches with the active nickname.
     * - If found, updates the score record exclusively if the new value breaks their historical personal best.
     * - If the user is new, inserts a fresh node directly into the vector array.
     * - Sorts the dataset in descending order using an inline custom lambda predicate evaluation.
     * - Stream-dumps the records down into "ranking.txt" and synchronizes the parent Game entity vector.
     */
    void save();

};