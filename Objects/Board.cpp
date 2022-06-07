//
// Created by Шамиль Валиев on 14.05.2022.
//

#include "Board.h"

extern sf::RenderWindow window;

void Board::make() {
    for (int i=0; i<64; i++){
        tiles[i].setRadius(130);
        tiles[i].setPointCount(4);
        tiles[i].rotate(45);
        tiles[i].setPosition((i % 8)*182 + 110, (i / 8)*182 - 70);
        if (i / 8 % 2 == 0){
            if (i % 2 == 0) {
                tiles[i].setFillColor(sf::Color(200, 200, 200));
            } else {
                tiles[i].setFillColor(sf::Color(50, 50, 50));
            }
        } else {
            if (i % 2 == 0) {
                tiles[i].setFillColor(sf::Color(50, 50, 50));
            } else {
                tiles[i].setFillColor(sf::Color(200, 200, 200));
            }
        }
//        window.draw(tiles[i]);
    }
}

void Board::draw() {
    for (sf::CircleShape& it : tiles){
        window.draw(it);
    }
}
