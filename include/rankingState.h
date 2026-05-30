#pragma once
#include "state.h"
#include "button.h"
#include "game.h"
#include "playState.h"
#include "nameState.h"
#include "menuState.h"
#include <fstream>
#include <vector>

/**
 * @class RankingState
 * @brief Handles the high-score leaderboard screen.
 * 
 * This state is responsible for reading player scores from a persistent storage file 
 * ("ranking.txt"), formatting the raw data into a text-based leaderboard layout, 
 * and allowing the user to navigate back to the main menu view.
 */
class RankingState : public State {
private:
    Button back_bnt;        /**< Navigation button used to return to the main menu state. */
    sf::Text ranking_txt;   /**< Graphical SFML text object used to display the formatted leaderboard. */

public:

    /**
     * @brief Constructs the Ranking State screen.
     * 
     * Fetches the necessary font assets, pre-configures the typography settings 
     * for the ranking text display, creates the navigation "BACK" button, and 
     * triggers an immediate disk read to fetch up-to-date score profiles.
     * 
     * @param game Pointer to the main core Game engine context.
     */
    RankingState(Game* game);

    /**
     * @brief Polls and responds to user interaction events unique to the scoreboard screen.
     * 
     * Specifically checks for button click interactions on the back button to 
     * shift execution focus back to the menu structure.
     * 
     * @param event Reference to the active SFML system event packet.
     */
    void handleEvents(sf::Event& event) override;

    /**
     * @brief Updates logical behaviors or animations for the ranking screen frame.
     * 
     * @note This screen relies entirely on static file listings and user events, 
     *       leaving this method deliberately empty.
     */
    void update() override;

    /**
     * @brief Dispatches the active screen elements to the display window buffer.
     * 
     * @param window Target rendering context window reference.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Dynamically transforms score profiles into a scrollable visual ledger layout.
     * 
     * Resolves high-score profiles extracted from the main engine data layout, 
     * appends names and values into an aligned listing, assigns it to the local 
     * text buffer interface, and renders the composite block directly onto the screen.
     * 
     * @param window Target rendering context window reference.
     */
    void drawRanking(sf::RenderWindow& window);
    
    /**
     * @brief Formats global UI typography, spacing, and sizing rules for text blocks.
     * 
     * Binds the proper loaded font configuration asset, configures characters sizes, 
     * adjusts inner fill color shades, and applies outer text outlines for optimal readability.
     * 
     * @param text Reference to the targeted sf::Text object to format.
     */
    void txt_sett(sf::Text& text);
};