#include "objects/object.h"
#include "helpers.h"

Object::Object(const sf::Vector2f &posn, const sf::Vector2f &size, const sf::Color color) : posn{posn}, size{size}

{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

Object::Object(const Object &obs) : posn{obs.get_posn()}, size{obs.get_size()}, shape{obs.get_shape()} {}

Object::Object(float x, float y, float w, float h, sf::Color color) : posn{x, y}, size{w, h}
{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

bool Object::at_posn(const sf::RectangleShape test_shape) const
{
    return shape.getGlobalBounds().intersects(test_shape.getGlobalBounds());
}
