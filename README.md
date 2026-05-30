# Snake Game (C++ / SFML)

A classic Snake game implemented in C++ using the SFML library.

## Features

* Main menu
* Player name input
* Snake movement using WASD
* Food spawning system
* Score tracking
* Collision detection
* High score ranking saved to file
* Game Over screen
* Object-oriented architecture based on State Pattern

## Technologies

* C++
* SFML
* STL (vector, string, fstream)

## Architecture

The application uses the State Pattern to separate game screens and logic:

* MenuState
* NameState
* PlayState
* EndState
* RankingState

Additional components:

* Snake
* Food
* GameMap
* Button
* Textbox
* AssetManager (Singleton)

## Controls

| Key | Action     |
| --- | ---------- |
| W   | Move Up    |
| S   | Move Down  |
| A   | Move Left  |
| D   | Move Right |

## Build Requirements

* C++17 compatible compiler
* SFML 2.x

## Future Improvements

* Sound effects
* Difficulty levels
* Multiplayer mode
* Online leaderboard
* Additional game modes

## Author

Jakub Łuczyński
