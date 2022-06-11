//
// Created by Шамиль Валиев on 07.06.2022.
//

#include "Dot.h"

extern sf::RenderWindow window;
sf::Color color(sf::Color(50, 50, 50));

void Dot::setLeftDown(int x, int y, Dot* father) {
    _father = father;
    leftDown = std::make_unique<Dot>();
    leftDown->dot.setRadius(50);
    leftDown->dot.setPosition(x + 25, y + 25);
    leftDown->dot.setFillColor(color);
}

void Dot::setRightDown(int x, int y, Dot* father) {
    _father = father;
    rightDown = std::make_unique<Dot>();
    rightDown->dot.setRadius(50);
    rightDown->dot.setPosition(x + 25, y + 25);
    rightDown->dot.setFillColor(color);
}

void Dot::setLeftUp(int x, int y, Dot* father) {
    _father = father;
    leftUp = std::make_unique<Dot>();
    leftUp->dot.setRadius(50);
    leftUp->dot.setPosition(x + 25, y + 25);
    leftUp->dot.setFillColor(color);
}

void Dot::setRightUp(int x, int y, Dot* father) {
    _father = father;
    rightUp = std::make_unique<Dot>();
    rightUp->dot.setRadius(50);
    rightUp->dot.setPosition(x + 25, y + 25);
    rightUp->dot.setFillColor(color);
}

void Dot::draw() {
    if (leftUp){
        window.draw(leftUp->dot);
        leftUp->draw();
    }
    if (leftDown){
        window.draw(leftDown->dot);
        leftDown->draw();
    }
    if (rightUp){
        window.draw(rightUp->dot);
        rightUp->draw();
    }
    if (rightDown){
        window.draw(rightDown->dot);
        rightDown->draw();
    }
}

void Dot::resetChildren() {
    leftUp = nullptr;
    leftDown = nullptr;
    rightUp = nullptr;
    rightDown = nullptr;
}




