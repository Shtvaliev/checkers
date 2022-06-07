//
// Created by Шамиль Валиев on 14.05.2022.
//

#include "Checkers.h"

extern sf::RenderWindow window;
extern bool display;


void Checkers::makeCheckers() {
    for (int i=0; i<12; i++){
        checkers[i].setRadius(75);
        checkers[i].setPosition((i % 4)*182*2 + 33 + 182*(i /4 % 2), (i / 4)*182 + 37);
        texture.loadFromFile("../Resources/checker.png");
        checkers[i].setTexture(&texture);

        window.draw(checkers[i]);
    }

    for (int i=12; i<24; i++){
        checkers[i].setRadius(75);
        checkers[i].setPosition((i % 4)*182*2 + 33 + 182*(i /4 % 2), (i / 4)*182 + 37 + 182*2);
        texture.loadFromFile("../Resources/checker.png");
        checkers[i].setTexture(&texture);
        checkers[i].setFillColor(sf::Color(170, 140, 80));

//        window.draw(checkers[i]);
    }
}

void Checkers::moveCheckers() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (sf::CircleShape& it : checkers){
        if (it.getGlobalBounds().contains(mousePos.x, mousePos.y)){
//            it.move(mousePos.x - it.getPosition().x, mousePos.y - it.getPosition().y);
            it.setPosition(mousePos.x, mousePos.y);
            display = true;
        }
    }
}

void Checkers::drawCheckers() {
    for (sf::CircleShape& it : checkers){
        window.draw(it);
    }
}
