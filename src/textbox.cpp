#include "textbox.h"

void Textbox::CreateTextbox(sf::Vector2f size, sf::Vector2f position, sf::Font& font, sf::Color color){
    
    textbox.setSize(sf::Vector2f(size));
    textbox.setOrigin(size.x/2,size.y/2);
    textbox.setPosition(position);
    textbox.setFillColor(color);
    textbox.setOutlineThickness(2);
    textbox.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(size.y-15);
    text.setOrigin(text.getOrigin().x, text.getCharacterSize()-5);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x-120,position.y);
    
}
void Textbox::IsActive(sf::RenderWindow& window, const sf::Event& event){

    if(event.type == sf::Event::MouseButtonPressed){
       
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        
        if(textbox.getGlobalBounds().contains(mousePos)){
            active = true;
        } else {
            active = false;
        }
    }

    if(active){
        if(event.type == sf::Event::TextEntered){
            if(event.text.unicode == 8){ // backspace
                if(!input.empty()){
                    input.pop_back();
                }
            }

            else if(event.text.unicode < 128 && event.text.unicode != 13 && event.text.unicode != 27){
                input += static_cast<char>(event.text.unicode);
            }
        }

        text.setString(input + "|");
    }
    else{
        text.setString(input);
    }
}

void Textbox::Draw(sf::RenderWindow& window){
    window.draw(textbox);
    window.draw(text);
}
void Textbox::GetText(std::string& text){
    text=input;
}