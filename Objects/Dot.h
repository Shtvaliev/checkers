#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief Dot object class
 */

class Dot {
private:
    sf::CircleShape dot; //!< dot sprite
    std::unique_ptr<Dot> leftUp, leftDown,
                                    rightUp, rightDown; //!< children dots
    Dot* _father; //!< pointer to the main dot that associated with a checker
public:
    /**
     * @brief Default constructor
     */
    Dot() : dot(),
            leftDown(nullptr),
            leftUp(nullptr),
            rightDown(nullptr),
            rightUp(nullptr),
            _father(nullptr) {}
    /**
     * @brief Copying constructor
     * @param it source object
     */
    Dot(Dot const &it) : dot(it.dot),
                        leftUp(it.leftUp.get()),
                        leftDown(it.leftDown.get()),
                        rightDown(it.rightDown.get()),
                        rightUp(it.rightUp.get()) { _father = it._father;}
    /**
     * @brief Set left up dot
     * @param x x coordinate
     * @param y y coordinate
     * @param father pointer to main dot
     *
     * Configure a new dot on left up direction regarding current
     */
    void setLeftUp(int x, int y, Dot* father);
    /**
     * @brief Get left up dot
     * @return pointer to the dot
     *
     * Allows interact with the dot on left up direction regarding current
     */
    Dot* getLeftUp() {return leftUp.get();}
    /**
     * @brief Set left down dot
     * @param x x coordinate
     * @param y y coordinate
     * @param father pointer to main dot
     *
     * Configure a new dot on left down direction regarding current
     */
    void setLeftDown(int x, int y, Dot* father);
    /**
     * @brief Get left down dot
     * @return pointer to the dot
     *
     * Allows interact with the dot down left up direction regarding current
     */
    Dot* getLeftDown() {return leftDown.get();}
    /**
     * @brief Set right up dot
     * @param x x coordinate
     * @param y y coordinate
     * @param father pointer to main dot
     *
     * Configure a new dot on right up direction regarding current
     */
    void setRightUp(int x, int y, Dot* father);
    /**
     * @brief Get right up dot
     * @return pointer to the dot
     *
     * Allows interact with the dot down right up direction regarding current
     */
    Dot* getRightUp() {return rightUp.get();}
    /**
     * @brief Set right down dot
     * @param x x coordinate
     * @param y y coordinate
     * @param father pointer to main dot
     *
     * Configure a new dot on right down direction regarding current
     */
    void setRightDown(int x, int y, Dot* father);
    /**
     * @brief Get right down dot
     * @return pointer to the dot
     *
     * Allows interact with the dot down right down direction regarding current
     */
    Dot* getRightDown() {return rightDown.get();}
//    void set() {}
    /**
     * Dot sprite getter
     * @return a link do dot's sprite
     *
     * Allows to interact with the dot
     */
    sf::CircleShape* getDot() {return &dot;}
    /**
     * @brief Children deleter
     *
     * Delete dots on all nearest directions
     */
    void resetChildren();
    /**
     * @brief Father getter
     * @return main's dot pointer
     *
     * Allows to interact with the first dot
     */
    Dot* getFather() { return _father;}
    /**
     * @brief Draw dot
     * @param window main game window
     *
     * Draws main dot and all children on the main game window
     */
    void draw(sf::RenderWindow& window);
};