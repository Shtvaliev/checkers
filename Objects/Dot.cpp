//
// Created by Шамиль Валиев on 07.06.2022.
//

#include "Dot.h"
#include "Window.h"

//extern sf::RenderWindow window;
sf::Color color(sf::Color(50, 50, 50));

void Dot::setLeftDown(int x, int y, Dot* father) {
    leftDown = std::make_unique<Dot>();
    leftDown->dot.setRadius(50);
    leftDown->dot.setPosition(x + 25, y + 25);
    leftDown->dot.setFillColor(color);
    leftDown->_father = father;
}

void Dot::setRightDown(int x, int y, Dot* father) {
    rightDown = std::make_unique<Dot>();
    rightDown->dot.setRadius(50);
    rightDown->dot.setPosition(x + 25, y + 25);
    rightDown->dot.setFillColor(color);
    rightDown->_father = father;
}

void Dot::setLeftUp(int x, int y, Dot* father) {
    leftUp = std::make_unique<Dot>();
    leftUp->dot.setRadius(50);
    leftUp->dot.setPosition(x + 25, y + 25);
    leftUp->dot.setFillColor(color);
    leftUp->_father = father;
}

void Dot::setRightUp(int x, int y, Dot* father) {
    rightUp = std::make_unique<Dot>();
    rightUp->dot.setRadius(50);
    rightUp->dot.setPosition(x + 25, y + 25);
    rightUp->dot.setFillColor(color);
    rightUp->_father = father;
}

void Dot::draw(sf::RenderWindow& window) {
    if (leftUp){
        window.draw(leftUp->dot);
        leftUp->draw(window);
    }
    if (leftDown){
        window.draw(leftDown->dot);
        leftDown->draw(window);
    }
    if (rightUp){
        window.draw(rightUp->dot);
        rightUp->draw(window);
    }
    if (rightDown){
        window.draw(rightDown->dot);
        rightDown->draw(window);
    }
}

void Dot::resetChildren() {
    leftUp = nullptr;
    leftDown = nullptr;
    rightUp = nullptr;
    rightDown = nullptr;
}




