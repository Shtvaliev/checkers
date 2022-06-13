//
// Created by Шамиль Валиев on 14.05.2022.
//

#include "Board.h"


sf::Vector2i posBoard(const int Wight,
                 const int Step, 
                 const int X0, 
                 const int Y0, 
                 int i){
    sf::Vector2i answer((i % Wight)*Step + X0, (i / Wight)*Step + Y0);
    return answer;
}


sf::Color color(int i, const int Wight){
    if (i / Wight % 2 == 0){
        if (i % 2 == 0) {
            return {200, 200, 200};
        } else {
            return {50, 50, 50};
        }
    } else {
        if (i % 2 == 0) {
            return {50, 50, 50};
        } else {
            return {200, 200, 200};
        }
    }
}


void Board::make(const int Wight, const int Step) {
    const int MaxTiles = 64;
    const int X0 = 110;
    const int Y0 = -70;
    
    for (int i=0; i<MaxTiles; ++i){
        _tiles[i].setRadius(130);
        _tiles[i].setPointCount(4);
        _tiles[i].rotate(45);
        _tiles[i].setPosition(posBoard(Wight, Step, X0, Y0, i).x,
                              posBoard(Wight, Step, X0, Y0, i).y);
        _tiles[i].setFillColor(color(i, Wight));
    }
}


void Board::draw(sf::RenderWindow& window) {
    for (sf::CircleShape& it : _tiles){
        window.draw(it);
    }
}
