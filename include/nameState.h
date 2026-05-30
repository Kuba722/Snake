#pragma once
#include "state.h"
#include "button.h"
#include "game.h"
#include "textbox.h"
#include "playState.h"
#include <string>

/**
 * @class NameState
 * @brief Handles the player name input screen before starting a game.
 * 
 * This state provides an interactive interface featuring an editable input box 
 * (Textbox) and a confirmation trigger (Button). It ensures the player identity 
 * is captured and registered inside the global engine core before routing execution 
 * context into the live play environment loop.
 */
class NameState : public State {
private:
    Button go_btn;      /**< Action button used to validate input and transition into the gameplay state. */
    Textbox textbox;    /**< Dynamic text entry field component catching keyboard keystrokes from the player. */

public:

    /**
     * @brief Constructs the Name Entry screen environment.
     * 
     * Grabs the default shared typography font mapping from the asset manager system, 
     * configures the functional geometry bounding size and positions for the "GO" action 
     * interface button, and instantiates the focusable input textbox framework.
     * 
     * @param game Pointer to the main core Game engine lifecycle manager.
     */
    NameState(Game* game);

    /**
     * @brief Distributes hardware event dispatches to the internal screen components.
     * 
     * Coordinates input focus switching for the text layout block based on selection cues 
     * and evaluates click interactions on the verification button. If a non-empty name 
     * value is retrieved, it updates the session state memory profile and triggers a switch to PlayState.
     * 
     * @param event Reference to the active SFML system event interaction packet.
     */
    void handleEvents(sf::Event& event) override;

    /**
     * @brief Updates logical state variables or animation parameters for the entry screen frame.
     * 
     * @note This layout acts entirely as a static utility frame responding to discrete user actions, 
     *       leaving this method intentionally empty.
     */
    void update() override;

    /**
     * @brief Dispatches the input interface visual targets to the active frame display buffer.
     * 
     * Draws the interactive typing box region overlay first, followed by the verification 
     * submission trigger button context on top.
     * 
     * @param window Target rendering context window destination reference.
     */
    void render(sf::RenderWindow& window) override;

};