#pragma once
#include "Dot.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Checker.h"
//#include "Window.h"

class Checkers {
private:
    Checker _checker[24];
public:
    void make(int wight, int step);
    Checker* move(Checker* ch, sf::RenderWindow& window, bool& display);
    void draw(sf::RenderWindow& window);
    Checker* showDots(bool step,
                      sf::RenderWindow& window,
                      bool& display,
                      const int Step);
    void setDot(bool step, Dot* dot, Dot* fa);
    void cleanUp(Dot* dot);
};

sf::Vector2i posChecker(int i,
                        int Wight,
                        const int Step,
                        const int dX,
                        const int dY);