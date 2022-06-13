#pragma once
#include <SFML/Graphics.hpp>

class Board{
private:
    sf::CircleShape _tiles[64];
public:
    void make(int wight, int step);
    void draw(sf::RenderWindow& window);
};