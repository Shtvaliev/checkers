#pragma once
#include <SFML/Graphics.hpp>


class Checkers {
private:
    sf::CircleShape checkers[24];
    sf::Texture texture;
public:
    void makeCheckers();
    void moveCheckers();
    void drawCheckers();
};