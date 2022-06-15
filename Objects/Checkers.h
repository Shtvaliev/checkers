#pragma once
#include "Dot.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Checker.h"

/**
 * @brief Checkers object class
 */

class Checkers {
private:
    Checker _checker[24];//!< massive of checker's sprites
public:
    /**
     * @brief Checkers maker
     * @param wight number of checkers in one row
     * @param step distance between checkers
     *
     * Configure checker's sprites
     */
    void make(int wight, int step);
    /**
     * @brief Checker mover
     * @param ch pointer to the checker that will be moved
     * @param window main game window
     * @param display for message about necessary to display changes
     * @return pointer to moved checker
     *
     * Move checker to the new position
     */
    Checker* move(Checker* ch, sf::RenderWindow& window, bool& display);
    /**
     * @brief Draw checker
     * @param window main game window
     *
     * Draws checker on the main game window
     */
    void draw(sf::RenderWindow& window);
    /**
     * @brief Context helper
     * @param step distance between checkers
     * @param window main game window
     * @param display for message about necessary to display changes
     * @param Step distance between checkers
     * @param mousePos mouse position
     * @return the pointer on checker that was pressed
     *
     *
     */
    Checker* showDots(bool step,
                      sf::RenderWindow& window,
                      bool& display,
                      const int Step,
                      sf::Vector2i mousePos);
//    void setDot(bool step, Dot* dot, Dot* fa);
    /**
     * @brief Dot's deleter
     * @param dot parent's dot pointer
     *
     * Delete all helper dots after using
     */
    void cleanUp(Dot* dot);
};

/**
 * @brief Checker position
 * @param i checker number
 * @param Wight number of checkers in one row
 * @param Step distance between checkers
 * @param dX x coordinate of the first checker
 * @param dY y coordinate of the first checker
 * @return SFML int vector containing x and y coordinates of checker
 */
sf::Vector2i posChecker(int i,
                        int Wight,
                        const int Step,
                        const int dX,
                        const int dY);