#include "endState.h"
#include "assetManager.h"
#include "game.h" 
#include "playState.h"
#include "menuState.h"

EndState::EndState(Game* game) : State(game) {
   
    sf::Font& font = AssetManager::getInstance().getFont("ARIALI.ttf");
      
    play_again_bnt.createButton({220,50}, font, "PLAY AGAIN", sf::Color::Blue,{250,350});
    menu_bnt.createButton({220,50}, font, "MENU", sf::Color::Blue,{250,450});

    score_txt.setString("Score: " + std::to_string(gameContext->getScore()));
    score_txt.setPosition(100,150);    
    txt_sett(score_txt);

    player_txt.setString("PLAYER: " + gameContext->getName());
    player_txt.setPosition(100,100);
    txt_sett(player_txt);

    over_txt.setString("GAME OVER");
    over_txt.setPosition(150,50);
    txt_sett(over_txt);
    
    save();    
}

    
void EndState::handleEvents(sf::Event& event){
    if(play_again_bnt.actionListener(gameContext->window, event)){
        gameContext->setScore(0); 
        gameContext->changeState(new PlayState(gameContext));
    }
    if(menu_bnt.actionListener(gameContext->window, event)){
        gameContext->setScore(0);
        gameContext->changeState(new MenuState(gameContext));
    }
}

void EndState::update(){
    //nothing
}

void EndState::render(sf::RenderWindow& window){

    play_again_bnt.draw(window);
    menu_bnt.draw(window);

    window.draw(score_txt);
    window.draw(player_txt);
    window.draw(over_txt);

}

void EndState::txt_sett(sf::Text& text){
    text.setFont(AssetManager::getInstance().getFont("ARIALI.ttf"));
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setOutlineThickness(3);
    text.setOutlineColor(sf::Color::Yellow);
}


void EndState::save(){

    bool found=false;
    bool new_save=false;
    std::vector<Score_s> currentRanking = gameContext->getRanking();
    std::string playerName = gameContext->getName();
    int score = gameContext->getScore();

    for(auto& s : currentRanking){

        if(s.name==playerName){
            found=true;

            if(score>s.points){
                s.points=score;
                new_save=true;
            }
        }
    }
    if(!found){
        currentRanking.push_back({score,playerName});
        new_save=true;
    }
    if(new_save){
        std::sort(currentRanking.begin(), currentRanking.end(),
        [](const Score_s& a, const Score_s& b) {
            return a.points > b.points;
        });

        std::ofstream zapis("ranking.txt");

        for (const auto& s : currentRanking) {
            zapis << s.name << " " << s.points << "\n";
        }
        gameContext->setRanking(currentRanking);
    }
}