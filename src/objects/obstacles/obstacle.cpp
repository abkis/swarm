#include "objects/obstacles/obstacle.h"

Obstacle::Obstacle(sf::Vector2f &posn, sf::Vector2f &size, sf::Color color) : Object{posn, size, color}

{
}

Obstacle::Obstacle(const Obstacle &obs) : Object(obs.get_posn(), obs.get_size(), obs.get_color())
{
}

Obstacle::Obstacle(const Object &obj) : Object(obj) {}

Obstacle::Obstacle(float x, float y, float w, float h, sf::Color color) : Object(x, y, w, h, color)
{
}
