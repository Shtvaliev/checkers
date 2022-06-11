//
// Created by Шамиль Валиев on 11.06.2022.
//

#include "Checker.h"

extern sf::RenderWindow window;
extern bool display;

void Checker::setTexture(std::string s){
    texture.loadFromFile(s);
    checker.setTexture(&texture);
}

void Checker::setDot(std::string s, int x, int y, Dot* fa) {
    if (s == "leftDown"){
        dot.setLeftDown(x, y, fa);
    }
    else if (s == "rightDown"){
        dot.setRightDown(x, y, fa);
    }
    else if (s == "leftUp"){
        dot.setLeftUp(x, y, fa);
    }
    else if (s == "rightUp"){
        dot.setRightUp(x, y, fa);
    }
}

void Checker::delChecker() {
    checker.setPosition(-100, -100);
}

