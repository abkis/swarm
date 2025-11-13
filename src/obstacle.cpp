#include "obstacle.h"

Obstacle::Obstacle(sf::Vector2f &posn, sf::Vector2f &size, sf::Color color) : posn{posn}, size{size}

{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

Obstacle::Obstacle(Obstacle &obs) : posn{obs.get_posn()}, size{obs.get_size()}, shape{obs.get_shape()} {}

Obstacle::Obstacle(float x, float y, float w, float h, sf::Color color) : posn{x, y}, size{w, h}
{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

bool Obstacle::at_posn(const sf::RectangleShape test_shape) const
{
    return shape.getGlobalBounds().intersects(test_shape.getGlobalBounds());
}