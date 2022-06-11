#pragma once
#include "Dot.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Checker.h"

class Checkers {
private:
    Checker checker[24];
public:
    void make();
    Checker* move(Checker* ch);
    void draw();
    Checker* showDots(bool step);
    void setDot(bool step, Dot* dot, Dot* fa);
    void cleanUp(Dot* dot);
};