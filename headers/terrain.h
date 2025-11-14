#pragma once
#include "obstacle.h"
#include <memory>
// handles terrain

class Terrain
{
    float width, height;
    std::vector<std::unique_ptr<Obstacle>> obstacles; // vector of obstacles
public:
    Terrain(float w, float h, int num_obstacles); // create terration with sufficiently many obstacles

    float cast_ray(sf::Vector2f posn, sf::Vector2f dir, float range) const; // returns distance to oject if in sensor range. If no object returns -1
};