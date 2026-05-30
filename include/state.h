#pragma once
#include <SFML/Graphics.hpp>

class Game;

/**
 * @class State
 * @brief Abstract base class representing a generic state in the game engine.
 * * This class serves as the interface for the State Pattern. Every individual screen 
 * (such as the Main Menu, Gameplay screen, Highscores leaderboard, or Game Over screen) 
 * inherits from this class and overrides its pure virtual methods to implement custom, 
 * isolated runtime logic.
 */
class State {
protected:

    /**
     * @brief Pointer back to the core Game engine context.
     * * Provides the derived states with a vital handle to access shared session metadata 
     * (e.g., active player names, live score metrics, leaderboard vectors) and allows 
     * states to request active screen transitions via the parent's runtime system.
     */
    Game* gameContext;

public:

    /**
     * @brief Constructs a State object and binds it to the core engine context.
     * * @param game Direct pointer back to the primary engine orchestrator instance.
     */
    State(Game* game) : gameContext(game) {}

    /**
     * @brief Virtual destructor to ensure flawless lifecycle teardowns.
     * * Guarantees that when a state pointer is safely deleted at the end of a game loop, 
     * the specific overriding class destructor (e.g., ~PlayState or ~MenuState) executes 
     * completely, preventing memory leaks or resource allocations from sticking around.
     */
    virtual ~State() = default;

    /**
     * @brief Pure virtual method to handle unique polling inputs for the active state.
     * * Must be implemented by the child class to handle mouse clicks, keystrokes, 
     * or structural interface updates localized to that specific screen layout.
     * * @param event Reference to the active hardware event packet currently parsed.
     */
    virtual void handleEvents(sf::Event& event) = 0;

    /**
     * @brief Pure virtual method to update the specific internal logic of the active state.
     * * Executed automatically on every frame lifecycle step. Used to tick gameplay 
     * animations, refresh spatial coordinate states, or track scoring benchmarks.
     */
    virtual void update() = 0;

    /**
     * @brief Pure virtual method to render visual primitives unique to this state.
     * * Invoked continuously by the main loop. Every concrete state must fill this method 
     * to draw its own sprites, grids, text layers, or buttons to the screen buffer.
     * * @param window Target rendering context window destination reference.
     */
    virtual void render(sf::RenderWindow& window) = 0;
};