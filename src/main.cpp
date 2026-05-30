#include "game.h"
#include "playState.h" 
#include <ctime>
#include <cstdlib>
#include"menuState.h"

int main(){

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Game game;

    game.setScore(0);

    game.changeState(new MenuState(&game));

    game.run();

    return 0;
}