#pragma once
//#include "Checkers.h"
#include <SFML/Graphics.hpp>
//#include "Checkers.h"

class Dot {
private:
    sf::CircleShape dot;
    std::unique_ptr<Dot> leftUp, leftDown,
                                    rightUp, rightDown;
    Dot* _father;
public:
    Dot() : dot(),
            leftDown(nullptr),
            leftUp(nullptr),
            rightDown(nullptr),
            rightUp(nullptr),
            _father(nullptr) {}
    Dot(Dot const &it) : dot(it.dot),
                        leftUp(it.leftUp.get()),
                        leftDown(it.leftDown.get()),
                        rightDown(it.rightDown.get()),
                        rightUp(it.rightUp.get()) { _father = it._father;}
    void setLeftUp(int x, int y, Dot* father);
    Dot* getLeftUp() {return leftUp.get();}
    void setLeftDown(int x, int y, Dot* father);
    Dot* getLeftDown() {return leftDown.get();}
    void setRightUp(int x, int y, Dot* father);
    Dot* getRightUp() {return rightUp.get();}
    void setRightDown(int x, int y, Dot* father);
    Dot* getRightDown() {return rightDown.get();}
    void set() {}
    sf::CircleShape* getDot() {return &dot;}
    void resetChildren();
    Dot* getFather() { return _father;}

    void draw(sf::RenderWindow& window);
};