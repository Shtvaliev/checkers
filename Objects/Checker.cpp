//
// Created by Шамиль Валиев on 11.06.2022.
//

#include "Checker.h"


void Checker::setTexture(std::string s){
    _texture.loadFromFile(s);
    _checker.setTexture(&_texture);
}

void Checker::setDot(std::string s, int x, int y, Dot* fa) {
    if (s == "leftDown"){
        _dot.setLeftDown(x, y, fa);
    }
    else if (s == "rightDown"){
        _dot.setRightDown(x, y, fa);
    }
    else if (s == "leftUp"){
        _dot.setLeftUp(x, y, fa);
    }
    else if (s == "rightUp"){
        _dot.setRightUp(x, y, fa);
    }
}

void Checker::delChecker() {
    _checker.setPosition(-100, -100);
}

