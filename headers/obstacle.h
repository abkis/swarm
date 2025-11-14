#pragma once
#include <SFML/Graphics.hpp>
#include "robots/robot.h"

// base class for obstacles in terrain
class Obstacle
{
    sf::Vector2f posn; // xy coordinate
    sf::Vector2f size; // width and height
    float elastic;

    sf::RectangleShape shape;

public:
    Obstacle(sf::Vector2f &posn, sf::Vector2f &size, sf::Color color, float elastic = 0);
    Obstacle(Obstacle &obs);
    Obstacle(float x, float y, float w, float h, sf::Color color);

    inline sf::Vector2f get_posn() const { return posn; }
    inline sf::Vector2f get_size() const { return size; }
    inline sf::RectangleShape get_shape() const { return shape; }

    sf::Vector2f collision_force(const Robot &robot, const sf::Vector2f posn) const;

    bool at_posn(const sf::RectangleShape test_rect) const; // check if intersect obstacle
};