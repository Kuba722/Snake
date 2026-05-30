#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "state.h"

/**
 * @struct Score_s
 * @brief Simple data container representing a single player's score entry.
 */
struct Score_s{
    int points;         /**< The numerical score achieved by the player. */
    std::string name;   /**< The player's display name associated with the score. */
};

/**
 * @class Game
 * @brief The main engine class managing the application lifecycle and global state.
 * * The Game class acts as the central controller using the State Pattern. It manages 
 * the primary game loop (run), maintains the persistent shared context (scores, player name, 
 * leaderboard), and handles safe transitions between different game states (Menu, Play, End, etc.)
 * to prevent memory leaks and dangling pointer crashes.
 */
class Game{

private:

    int score;                      /**< Current session score tracker. */
    std::string playerName;         /**< Captured player identifier for leaderboard tracking. */
    std::vector<Score_s> ranking;   /**< Cached leaderboard dataset shared across states. */
    State* currentState;            /**< Pointer to the currently active state being processed. */
    State* pendingState = nullptr;  /**< Buffer pointer for deferred state changes during the next loop cycle. */

public:
    sf::RenderWindow window;    /**< The main SFML rendering viewport managed by the game engine. */

    /**
     * @brief Constructs the Game engine.
     * * Initializes default score and player metadata, sets the initial null pointer for states, 
     * and instantiates the main application window with defined resolution settings.
     */
    Game();

    /**
     * @brief The core engine execution loop.
     * * Orchestrates the classic "Input -> Update -> Render" pattern:
     * 1. Polls hardware events (Close, keyboard/mouse input).
     * 2. Triggers logical logic updates via the current state.
     * 3. Renders the frame to the window.
     * 4. Performs a deferred state change safety check (deleting the old state pointer 
     * and assigning a new one to prevent memory corruption).
     */
    void run();

    /**
     * @brief Queues a state transition for the end of the current frame cycle.
     * 
     *  @param newState A pointer to the newly allocated state object.
     */
    void changeState(State* newState);

    /** @brief Sets the current session score. 
     * 
     * @param s Score value. 
     */
    void setScore(int s);
    
    /** @brief Retrieves the current session score. 
     * 
     * @return int Score value. 
     */
    int getScore();
    
    /** @brief Sets the player nickname. 
     * 
     * @param n Player name string.
     */
    void setName(std::string n);

    /** @brief Retrieves the player nickname. 
     * 
     * @return std::string Player name. 
     */
    std::string getName();

    /** @brief Synchronizes the local leaderboard cache. 
     * 
     * @param r Vector of score structures. 
     */
    void setRanking(std::vector<Score_s> r);

    /** @brief Retrieves the current cached leaderboard. 
     * 
     * @return std::vector<Score_s> Ranking data. 
     */
    std::vector<Score_s> getRanking();  
};
