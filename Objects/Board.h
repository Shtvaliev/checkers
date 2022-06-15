#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief Board object class
 */

class Board{
private:
    sf::CircleShape _tiles[64]; //!< massive of tile's sprites
public:
    /**
     * @brief Configure tiles sprites
     * @param wight number of tiles in one row
     * @param step distance between tiles
     *
     * Set parameters of each tile
     */
    void make(int wight, int step);
    /**
     * @brief Draw tiles
     * @param window main game window
     *
     * Draws all tiles on the main game window
     */
    void draw(sf::RenderWindow& window);
};

/**
 * @brief Tile position
 * @param Wight number of tiles in one row
 * @param Step distance between tiles
 * @param X0 x coordinate of the first tile
 * @param Y0 y coordinate of the first tile
 * @param i tile number
 * @return SFML int vector containing x and y coordinates of tile
 *
 * Find position of each tile by its number
 */
sf::Vector2i posBoard(const int Wight,
                      const int Step,
                      const int X0,
                      const int Y0,
                      int i);

/**
 * @brief Tile _color
 * @param i tile number
 * @param Wight number of tiles in one row
 * @return SFML _color
 *
 * Returns _color for tile by its number
 */
sf::Color color(int i, const int Wight);