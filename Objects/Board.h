#pragma once
#include <SFML/Graphics.hpp>

class Board{
private:
    sf::CircleShape tiles[64];
public:
    void makeBoard();
    void drawBoard();
};