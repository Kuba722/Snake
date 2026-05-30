#include "menuState.h"
#include "AssetManager.h"

MenuState::MenuState(Game* game) : State(game)  {        
    sf::Font& font = AssetManager::getInstance().getFont("ARIALI.ttf");

    play_bnt.createButton({220,50}, font, "PLAY", sf::Color::Blue,{250,150});
    ranking_bnt.createButton({220,50}, font, "RANKING", sf::Color::Blue,{250,250});
    exit_bnt.createButton({220,50}, font, "EXIT", sf::Color::Blue,{250,350});    
}

    
void MenuState::handleEvents(sf::Event& event){

    if (event.type == sf::Event::MouseButtonReleased) {

    }

    if(play_bnt.actionListener(gameContext->window,event)){
        gameContext->changeState(new NameState(gameContext));
    }
    if(ranking_bnt.actionListener(gameContext->window, event)){
        gameContext->changeState(new RankingState(gameContext));
    }
    if(exit_bnt.actionListener(gameContext->window, event)){
        gameContext->window.close();         
    }
}

void MenuState::update(){
    // nothing
}

void MenuState::render(sf::RenderWindow& window){
    play_bnt.draw(window);
    ranking_bnt.draw(window);
    exit_bnt.draw(window);
}