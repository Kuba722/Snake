#include "nameState.h"
#include "AssetManager.h"

NameState::NameState(Game* game) : State(game)  {

    sf::Font& font = AssetManager::getInstance().getFont("ARIALI.ttf");

    go_btn.createButton({220,50}, font, "GO", sf::Color::Blue,{250,350});
    textbox.CreateTextbox({500,40},{10*25,10*25},font,sf::Color::White);

}


void NameState::handleEvents(sf::Event& event){
        
    textbox.IsActive(gameContext->window, event);
    
    if(go_btn.actionListener(gameContext->window, event)) {
        std::string playerName;
        textbox.GetText(playerName);

        if(playerName != "") {
            gameContext->setName(playerName);
            gameContext->changeState(new PlayState(gameContext));
        }
    }
}

void NameState::update(){
    //nothing
}

   
void NameState::render(sf::RenderWindow& window){
    textbox.Draw(window);
    go_btn.draw(window);
}
