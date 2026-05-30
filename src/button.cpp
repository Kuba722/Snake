#include "button.h"

void Button::createButton(sf::Vector2f size, sf::Font& font, std::string text, sf::Color fillColor, sf::Vector2f position){
    button.setSize(sf::Vector2f(size));
    button.setOrigin(size.x/2.f,size.y/2.f);
    button.setPosition(position);
    button.setFillColor(fillColor);
    button.setOutlineThickness(2);
    button.setOutlineColor(sf::Color::Black);

    btnText.setFont(font);
    btnText.setString(text);
    sf::FloatRect textRect = btnText.getLocalBounds();
    btnText.setOrigin(text.length()*11, btnText.getCharacterSize());
    btnText.setPosition(button.getPosition());
    btnText.setCharacterSize(size.y-15);
    btnText.setFillColor(sf::Color::Black);
}

bool Button::actionListener(sf::RenderWindow& window, const sf::Event& event){

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if(button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))){
        
        if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
            return true;
        }
    }
        return false;
}


void Button::draw(sf::RenderTarget& target){
    target.draw(button);
    target.draw(btnText);
}