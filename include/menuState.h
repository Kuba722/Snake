#pragma once
#include "state.h"
#include "button.h"
#include "game.h"
#include "playState.h"
#include "nameState.h"
#include "rankingState.h"

/**
 * @class MenuState
 * @brief Handles the primary main menu screen overlay and navigation routing.
 * 
 * This state serves as the initial landing application hub, generating the interactive
 * button layout that maps input paths to core operational behaviors: entering player setup,
 * opening the high-score spreadsheet data table, or safely shutting down execution threads.
 */
class MenuState : public State {
private:
    Button play_bnt;    /**< Navigation trigger to jump forward into the name registration interface (NameState). */
    Button ranking_bnt; /**< Navigation trigger to fetch and open the offline scoreboard view (RankingState). */
    Button exit_bnt;    /**< Command trigger telling the window context wrapper to terminate rendering loops. */

public:

    /**
     * @brief Constructs the Main Menu state layout layer.
     * 
     * Hooks into the global shared typography map to extract the active font asset, 
     * sizes individual components to standard resolution boxes, binds distinct label 
     * values, and shifts vertical anchors to group the layout structure centrally.
     * 
     * @param game Pointer to the main core Game framework lifecycle driver.
     */
    MenuState(Game* game);

    /**
     * @brief Traverses human interaction signals to map window execution state jumps.
     * 
     * Polls event sequences matching position changes or boundary clicks. 
     * Forwards interaction hits on the "PLAY" component to NameState, redirects "RANKING" 
     * triggers to look up local save entries, and closes the application if "EXIT" fires.
     * 
     * @param event Reference to the active SFML system event tracking packet.
     */
    void handleEvents(sf::Event& event) override;

    /**
     * @brief Steps background thread processes or loop frames for the menu structures.
     * 
     * @note This layout acts entirely as a static utility frame responding to discrete user actions, 
     *       leaving this method intentionally empty.
     */
    void update() override;

    /**
     * @brief Flushes current menu asset graphics onto the active window target stream.
     * 
     * Renders the modular stack navigation layers directly onto the window canvas buffer,
     * maintaining ordered layer placement blocks for the action selection layout.
     * 
     * @param window Target rendering context window destination reference.
     */
    void render(sf::RenderWindow& window) override;
};