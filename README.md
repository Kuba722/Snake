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

## Screenshots

### Main Menu
<img width="416" height="445" alt="image" src="https://github.com/user-attachments/assets/a6f3c619-908b-4220-a530-01a34acdfa2a" />

### Gameplay

<img width="422" height="447" alt="image" src="https://github.com/user-attachments/assets/4f918be1-e471-428d-8855-6715f12d1557" />


### Ranking
<img width="415" height="448" alt="image" src="https://github.com/user-attachments/assets/8d70e84f-3d98-42bf-81a3-eb106f3eb552" />

### Game Over

<img width="419" height="448" alt="image" src="https://github.com/user-attachments/assets/11f96088-3407-4846-ad65-df0a0843e736" />


## Future Improvements

* Sound effects
* Difficulty levels
* Multiplayer mode
* Online leaderboard
* Additional game modes

## Author

Jakub Łuczyński
