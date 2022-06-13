#pragma once
#include "Dot.h"
#include <SFML/Graphics.hpp>
#include <string>
//#include "Window.h"

class Checker {
private:
    sf::CircleShape checker;
//    bool missis;
    bool color; // true-black, false-white
//    bool deleted = false;
    sf::Texture texture;
    Dot dot;
public:
    sf::CircleShape* getChecker(){ return &checker;}
    bool getColor() const{ return color;}
//    void setMissis(bool f){ missis = f;}
    void setColor(bool f){ color = f;}
    void setTexture(std::string s);
    void setDot(std::string s, int x, int y, Dot* fa);
    void drawDot(sf::RenderWindow& window){ dot.draw(window);}
    void delChecker();
//    void setDel(bool f){ deleted = f;}
//    bool ifDel(){ return deleted;}

    Dot* getDot() {return &dot;}
};