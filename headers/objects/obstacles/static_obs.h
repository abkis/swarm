#pragma once
#include "objects/obstacles/obstacle.h"

class StaticObs : public Obstacle
{
    float elastic;

public:
    StaticObs(sf::Vector2f &posn, sf::Vector2f &size, sf::Color color, float elastic = 0);
    StaticObs(Obstacle &obs, float e = 0);
    StaticObs(float x, float y, float w, float h, sf::Color color, float e = 0);

    sf::Vector2f collision_force(const Robot &robot, sf::Vector2f posn) const override;
};