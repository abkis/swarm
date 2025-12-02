#pragma once
#include "objects/obstacles/obstacle.h"
#include "objects/robots/robot.h"
#include <memory>
// handles terrain

class Obstacle;
class Robot;

class Terrain
{
    float width, height;
    std::vector<std::unique_ptr<Obstacle>> obstacles; // vector of obstacles
    std::vector<std::unique_ptr<Robot>> robots;       // vector of robots
public:
    Terrain(float w, float h, int num_obstacles); // create terration with sufficiently many obstacles
    inline void add_robot(std::unique_ptr<Robot> r) { robots.push_back(std::move(r)); };

    float cast_ray(sf::Vector2f posn, sf::Vector2f dir, float range) const;    // returns distance to oject if in sensor range. If no object returns -1
    std::vector<Robot *> find_neighbors(sf::Vector2f posn, float range) const; // return robots sensed by sensor
    std::pair<Obstacle *, sf::Vector2f> collision() const;                     // return weakptr to obstacle collided with
};