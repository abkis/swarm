#pragma once
#include <SFML/Graphics.hpp>

// base class for objects in terrain
class Object
{
    sf::Vector2f posn; // position in xy plane of object center
    sf::Vector2f size; // width and height

    sf::RectangleShape shape;

public:
    Object(const sf::Vector2f &posn, const sf::Vector2f &size, const sf::Color color);
    Object(const Object &obs);
    Object(float x, float y, float w, float h, sf::Color color);

    inline sf::Vector2f get_posn() const { return posn; }
    inline sf::Vector2f get_size() const { return size; }
    inline sf::RectangleShape get_shape() const { return shape; }
    inline sf::Color get_color() const { return shape.getFillColor(); }

    bool at_posn(const sf::RectangleShape test_rect) const;                                 // check if intersect object
    bool at_posn(const sf::Vector2f posn, const sf::Vector2f dir, const float range) const; // check if vector vect intesects object
};