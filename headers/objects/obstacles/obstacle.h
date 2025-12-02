#pragma once
#include <SFML/Graphics.hpp>
#include "objects/robots/robot.h"
#include "objects/object.h"

class Robot;

// base class for objects in terrain
class Obstacle : public Object
{
public:
    Obstacle(sf::Vector2f &posn, sf::Vector2f &size, sf::Color color);
    Obstacle(const Obstacle &obs);
    Obstacle(const Object &obs);
    Obstacle(float x, float y, float w, float h, sf::Color color);

    virtual ~Obstacle() = 0;
    virtual sf::Vector2f collision_force(const Robot &robot, const sf::Vector2f posn) const = 0;
};