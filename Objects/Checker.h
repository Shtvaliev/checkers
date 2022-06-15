#pragma once
#include "Dot.h"
#include <SFML/Graphics.hpp>
#include <string>

/**
 * @brief Single Checker object class
 */

class Checker {
private:
    sf::CircleShape _checker; //!< single checker sprite
//    bool missis;
    bool _color; //!< color of _checker: true<=>black, false<=>white
//    bool deleted = false;
    sf::Texture _texture; //! checker's sprite texture
    Dot _dot; //! parent dot, anchor for children
public:
    /**
     * @brief Dingle checker giver
     * @return link to the param *_checker*
     *
     * Allow to interact with a single checker
     */
    sf::CircleShape* getChecker(){ return &_checker;}
    /**
     * @brief Color giver
     * @return param *_color* – color of the checker
     *
     * Gives color of the single checker
     */
    bool getColor() const{ return _color;}
//    void setMissis(bool f){ missis = f;}
    /**
     * @brief Color setter
     * @param f color
     *
     * Sets color of the single checker
     */
    void setColor(bool f){ _color = f;}
    /**
     * @brief Texture setter
     * @param s path to the texture file
     *
     * Configure checker with the texture
     */
    void setTexture(std::string s);
    /**
     * @brief Dot setter
     * @param s direction of dot setting
     * @param x x coordinate
     * @param y y coordinate
     * @param fa pointer to the original dot
     *
     * Make a new dot with given direction, coordinates and parent
     */
    void setDot(std::string s, int x, int y, Dot* fa);
    /**
     * @brief Dot drawer
     * @param window main game window
     *
     * Display a new dot on the screen
     */
    void drawDot(sf::RenderWindow& window){ _dot.draw(window);}
    /**
     * @brief Checker deleter
     *
     * Hide a checker
     */
    void delChecker();
//    void setDel(bool f){ deleted = f;}
//    bool ifDel(){ return deleted;}
    /**
     * @brief Parent dot giver
     * @return link to parent dot param *_dot*
     *
     * Allows to interact with parent dot of a checker
     */
    Dot* getDot() {return &_dot;}
};