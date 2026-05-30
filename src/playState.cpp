#include "playState.h"
#include "game.h"
#include "endState.h"
#include "assetManager.h"
#include <string>
#include <cstdlib> 

PlayState::PlayState(Game* game) : State(game),
        map(15, 15),
        snake(0, 7),
        direction('d'),
        delay(0.23f),
        margin(3),
        cellSize(25),
        s(0)
        {

        

    score_txt.setString("Score: " + std::to_string(gameContext->getScore()));
    score_txt.setPosition(10,0);
    txt_sett(score_txt);
    player_txt.setString("PLAYER: "+ gameContext->getName());
    player_txt.setPosition(0,470);
    txt_sett(player_txt);

}

void PlayState::handleEvents(sf::Event& event){
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && direction != 's') direction = 'w';
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && direction != 'w') direction = 's';
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && direction != 'd') direction = 'a';
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && direction != 'a') direction = 'd';        
}

void PlayState::update(){
    if(clock.getElapsedTime().asSeconds() > delay){
        clock.restart();
        
        snake.move(direction);

        if(snake.getHead().x == food.getX() && snake.getHead().y == food.getY()){
            snake.eat();
            food.setX(rand() % map.getWidth());
            food.setY(rand() % map.getHeight());
            s++;
            gameContext->setScore(s);
            score_txt.setString("Score: " + std::to_string(s));
        }

        if(collision()){
            gameContext->changeState(new EndState(gameContext));
        }
    }
}

void PlayState::render(sf::RenderWindow& window){
    drawBoard(window);
    window.draw(score_txt);
    window.draw(player_txt);
            
    sf::RectangleShape foodShape(sf::Vector2f(cellSize, cellSize));
    foodShape.setFillColor(sf::Color::Red);
    foodShape.setPosition((food.getX()+margin) * cellSize, (food.getY()+margin) * cellSize);
    window.draw(foodShape);

    sf::RectangleShape head(sf::Vector2f(cellSize, cellSize));
       
     for(auto seg : snake.getBody()){
        
        sf::RectangleShape part(sf::Vector2f(cellSize, cellSize));
        part.setFillColor(sf::Color::Yellow);
        part.setPosition((seg.x+margin) * cellSize, (seg.y+margin) * cellSize);
        window.draw(part);
    }
    sf::Color head_color(150,150,0);
    head.setFillColor(head_color);
    head.setPosition((snake.getHead().x+margin) * cellSize, (snake.getHead().y+margin) * cellSize);
    window.draw(head);
        

        }
void PlayState::drawBoard(sf::RenderWindow& window){
    sf::Color green1(50,200,50);
    sf::Color green2(30,160,30);


    sf::RectangleShape grass(sf::Vector2f(cellSize,cellSize));

    for(int i=0;i<map.getHeight();i++){
        for(int j=0;j<map.getWidth();j++){
            grass.setPosition((margin+i)*cellSize,(margin+j)*cellSize);

            if((i+j)%2==0){
                grass.setFillColor(green1);
            }else{
                grass.setFillColor(green2); 
            }
            window.draw(grass);
        }

    }

}

bool PlayState::collision(){


    segment head = snake.getHead();

    if(head.x < 0 || head.y < 0 ||
        head.x >= map.getWidth() || head.y >= map.getHeight()){
        return true;
    }

        
    auto body = snake.getBody();
        
    for(int i = 1; i < body.size(); i++){
        if(head.x == body[i].x && head.y == body[i].y){
            return true;   
        }    
    }
    
    return false;
}


void PlayState::txt_sett(sf::Text& text){
        
    text.setFont(AssetManager::getInstance().getFont("ARIALI.ttf"));
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setOutlineThickness(3);
    text.setOutlineColor(sf::Color::Yellow);
}