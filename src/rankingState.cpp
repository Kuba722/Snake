#include "rankingState.h"
#include "AssetManager.h"


RankingState::RankingState(Game* game) : State(game)  {

    sf::Font& font = AssetManager::getInstance().getFont("ARIALI.ttf");
    txt_sett(ranking_txt);
    back_bnt.createButton({220,50}, font, "BACK", sf::Color::Blue,{250,50});
}

void RankingState::handleEvents(sf::Event& event){
    if(back_bnt.actionListener(gameContext->window, event)){
        gameContext->changeState(new MenuState(gameContext));
    }
}

void RankingState::update() {
    // nothing
}

void RankingState::render(sf::RenderWindow& window){
    back_bnt.draw(window);
    drawRanking(window);
}

void RankingState::drawRanking(sf::RenderWindow& window){
    std::string rankingText="--- RANKING ---\n\n";

    std::vector<Score_s> currentRanking = gameContext->getRanking();

    for(const auto& s : currentRanking){
        rankingText += s.name + " : " + std::to_string(s.points) + "\n";
    }

    ranking_txt.setString(rankingText);
    ranking_txt.setPosition(110,80);

    window.draw(ranking_txt);
}

void RankingState::txt_sett(sf::Text& text){
    text.setFont(AssetManager::getInstance().getFont("ARIALI.ttf"));
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setOutlineThickness(3);
    text.setOutlineColor(sf::Color::Yellow);
}