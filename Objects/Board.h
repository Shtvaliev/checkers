#pragma once
#include <SFML/Graphics.hpp>

class Board{
private:
    sf::CircleShape _tiles[64];
public:
    void make(int wight, int step);
    void draw(sf::RenderWindow& window);
};

sf::Vector2i posBoard(const int Wight,
                      const int Step,
                      const int X0,
                      const int Y0,
                      int i);

sf::Color color(int i, const int Wight);