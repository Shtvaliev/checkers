//
// Created by Шамиль Валиев on 07.06.2022.
//

#include "Dot.h"

extern sf::RenderWindow window;

void Dot::setLeftDown(int x, int y) {
    leftDown = std::make_unique<Dot>();
    leftDown.get()->dot.setRadius(50);
    leftDown.get()->dot.setPosition(x + 25, y + 25);
    leftDown.get()->dot.setFillColor(sf::Color::Yellow);
//    window.draw(leftDown.get()->dot);
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
