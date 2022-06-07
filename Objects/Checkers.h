#pragma once
#include "Dot.h"
#include <SFML/Graphics.hpp>
//#include "Dot.h"
#include <string>
//#include "Dot.h"

class Checker {
private:
    sf::CircleShape checker;
    bool missis;
    bool color; // true-black, false-white
    sf::Texture texture;
    Dot dot;
public:
    sf::CircleShape* getChecker(){ return &checker;}
//    Dot getDot(){ return dot;}
//    bool getMissisByNumber(int i){ return missis[i];}
    bool getColor() const{ return color;}
    void setMissis(bool f){ missis = f;}
    void setColor(bool f){ color = f;}
    void setTexture(std::string s);
    void setDot(std::string s, int x, int y);
    void drawDot(){ dot.draw();}
};

class Checkers {
private:
    Checker checker[24];
public:
    void make();
    void move();
    void draw();
    void showDots();
};