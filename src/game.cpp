#include "game.h"
#include "state.h"
#include <fstream>

Game::Game() : score(0), playerName("Player"), currentState(nullptr) {
    window.create(sf::VideoMode(525, 525), "Snake");

    std::ifstream file("ranking.txt");
    std::vector<Score_s> tempRanking;
    Score_s temp;
    
    if(file.is_open()) {
        while (file >> temp.name >> temp.points) {
            tempRanking.push_back(temp);
        }
        file.close();
    }
    
    ranking = tempRanking;
}
    
void Game::run() {
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
            
            if (currentState) currentState->handleEvents(event); 
        }
        
        if (currentState) currentState->update();

        window.clear();
        if (currentState) currentState->render(window);
        window.display();

        if (pendingState != nullptr) {
            if (currentState != nullptr) {
                delete currentState; 
            }
            currentState = pendingState; 
            pendingState = nullptr;     
        }
    }
}

void Game::changeState(State* newState) {
    pendingState = newState;
}

void Game::setScore(int s){
        score=s;
}

int Game::getScore(){
    return score;
}

void Game::setName(std::string n){
    playerName=n;
}

std::string Game::getName(){
    return playerName;
}

void  Game::setRanking(std::vector<Score_s> r){
    ranking=r;
}

std::vector<Score_s>  Game::getRanking(){
    return ranking;
}

    
  