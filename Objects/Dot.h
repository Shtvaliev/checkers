#pragma once
//#include "Checkers.h"
#include <SFML/Graphics.hpp>
//#include "Checkers.h"

class Dot {
private:
    sf::CircleShape dot;
    std::unique_ptr<Dot> leftUp, leftDown,
                                    rightUp, rightDown;
public:
    Dot() : dot(), leftDown(nullptr), leftUp(nullptr), rightDown(nullptr), rightUp(nullptr) {}
    Dot(Dot const &it) : dot(it.dot),
                        leftUp(it.leftUp.get()),
                        leftDown(it.leftDown.get()),
                        rightDown(it.rightDown.get()),
                        rightUp(it.rightUp.get()) {}
    void setLeftUp(int x, int y);
    void setLeftDown(int x, int y);
    void setRightUp(int x, int y);
    void setRightDown(int x, int y);

    void draw();
};