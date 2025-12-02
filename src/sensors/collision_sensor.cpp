#include "sensors/collision_sensor.h"
#include "objects/obstacles/obstacle.h"
#include "terrain.h"
#include <SFML/Graphics.hpp>

CollisionSensor::CollisionSensor() : Sensor(0) {}

void CollisionSensor::update(const Robot &robot, const Terrain &terrain)
{
    std::pair<Obstacle *, sf::Vector2f> info = terrain.collision();
    Obstacle *obs = info.first;
    if (obs == nullptr)
    {
        collision = false; // no collision
        return;
    }
    // otherwise there was a collision
    force = obs->collision_force(robot, info.second); // robot will need to get this info
}
