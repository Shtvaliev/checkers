//
// Created by Шамиль Валиев on 12.06.2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Checkers.h"

class Window{
private:
    sf::RenderWindow _window;
    bool _display;
    bool _step;
    bool _firstBoard;
    bool _firstCheckers;
    Board _board;
    Checkers _checkers;
    Checker* _currentChecker;
public:
    Window();
    sf::RenderWindow* getWindow(){ return &_window;}
    void setDisplay(bool f) { _display = f;}
};