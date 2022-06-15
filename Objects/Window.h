#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Checkers.h"


/**
 * @brief Game object checkers class
 */


class Window{
private:
    sf::RenderWindow _window; //!< main window
    bool _display; //!< shows if it necessary to display changes
    bool _step; //!< says whose turn it is now
    bool _firstBoard; //!< is it first time of boar drawing
    bool _firstCheckers; //!< is it first time of checkers drawing
    Board _board; //!< board object
    Checkers _checkers; //!< checkers object
    Checker* _currentChecker; //!< save checker that go now
    const int _Wight; //!< wight of board in number of tiles
    const int _Step;//!< number of pixels should be overcame to make a step
public:
    /**
     * @brief Default constructor
     */
    Window();
    /**
     * @brief Main loop
     *
     *Contain and starts main loop of graphic
     */
    void Do();
    /**
     * @brief Main window giver
     * @return link to the param *_window*
     *
     * Allow use main window
     */
    sf::RenderWindow* getWindow(){ return &_window;}
    /**
     * @brief Display switch setter
     * @param f It's necessary to show changes – true or false
     *
     * Allow set param *_display*
     */
    void setDisplay(bool f) { _display = f;}
};
