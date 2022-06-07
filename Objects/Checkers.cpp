//
// Created by Шамиль Валиев on 14.05.2022.
//

#include "Checkers.h"

extern sf::RenderWindow window;
extern bool display;

void Checker::setTexture(std::string s){
    texture.loadFromFile(s);
    checker.setTexture(&texture);
}

void Checker::setDot(std::string s, int x, int y) {
    if (s == "leftDown"){
        dot.setLeftDown(x, y);

    }
}


void Checkers::make() {
    for (int i=0; i<12; i++){
        checker[i].setMissis(false);
        checker[i].setColor(false);
        (*checker[i].getChecker()).setRadius(75);
        (*checker[i].getChecker()).setPosition((i % 4) * 182 * 2 + 33 + 182 * (i / 4 % 2), (i / 4) * 182 + 37);
        checker[i].setTexture("../Resources/checker.png");

        window.draw(*checker[i].getChecker());
    }

    for (int i=12; i<24; i++){
        checker[i].setMissis(false);
        checker[i].setColor(true);
        checker[i].getChecker()->setRadius(75);
        checker[i].getChecker()->setPosition((i % 4) * 182 * 2 + 33 + 182 * (i / 4 % 2), (i / 4) * 182 + 37 + 182 * 2);
        checker[i].setTexture("../Resources/checker.png");
        checker[i].getChecker()->setFillColor(sf::Color(170, 140, 80));

//        window.draw(checker[i]);
    }
}

void Checkers::showDots() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (Checker& it : checker){
        if ((*it.getChecker()).getGlobalBounds().contains(mousePos.x, mousePos.y)){

            if (it.getColor() == false){
                bool f = true;
                for (Checker& it2 : checker) {
                    if (it2.getChecker()->getGlobalBounds().contains(it.getChecker()->getPosition().x - 182,
                                                                     it.getChecker()->getPosition().y + 182)) {
                        f = false;
                    }
                }
                if (f) {
                    it.setDot("leftDown", it.getChecker()->getPosition().x - 182,
                              it.getChecker()->getPosition().y + 182);
                    display = true;
                }
            }
        }
    }
}

void Checkers::move() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (Checker& it : checker){
        if ((*it.getChecker()).getGlobalBounds().contains(mousePos.x, mousePos.y)){
//            it.move(mousePos.x - it.getPosition().x, mousePos.y - it.getPosition().y);
//            it.setPosition(mousePos.x, mousePos.y);

            display = true;
        }
    }
}

void Checkers::draw() {
    for (Checker& it : checker){
        window.draw(*it.getChecker());
        it.drawDot();
    }
}


