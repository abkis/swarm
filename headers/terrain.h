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
};