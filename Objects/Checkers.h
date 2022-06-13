#pragma once
#include "Dot.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Checker.h"
//#include "Window.h"

class Checkers {
private:
    Checker checker[24];
public:
    void make();
    Checker* move(Checker* ch, sf::RenderWindow& window, bool& display);
    void draw(sf::RenderWindow& window);
    Checker* showDots(bool step, sf::RenderWindow& window, bool& display);
    void setDot(bool step, Dot* dot, Dot* fa);
    void cleanUp(Dot* dot);
};