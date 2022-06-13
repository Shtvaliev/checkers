//
// Created by Шамиль Валиев on 14.05.2022.
//

#include "Board.h"


sf::Vector2i Pos(const int Wight, 
                 const int Step, 
                 const int X0, 
                 const int Y0, 
                 int i){
    sf::Vector2i answer((i % Wight)*Step + X0, (i / Wight)*Step - Y0);
    return answer;
}


sf::Color Color(int i, const int Wight){
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


void Board::make() {
    const int MaxTiles = 64;
    const int Wight = 8;
    const int Step = 182;
    const int X0 = 110;
    const int Y0 = -70;
    
    for (int i=0; i<MaxTiles; ++i){
        tiles[i].setRadius(130);
        tiles[i].setPointCount(4);
        tiles[i].rotate(45);
        tiles[i].setPosition(Pos(Wight, Step, X0, Y0, i).x, 
                             Pos(Wight, Step, X0, Y0, i).y);
        tiles[i].setFillColor(Color(i, Wight));
    }
}


void Board::draw(sf::RenderWindow& window) {
    for (sf::CircleShape& it : tiles){
        window.draw(it);
    }
}
