#include "sensors/proximity_sensor.h"
#include <cmath>
#include "robots/robot.h"

ProximitySensor::ProximitySensor(float range, float angle) : Sensor(range), angle_offset{angle} {}

// called on robot movement
// senses environment and determines if obstacle/etc in the way
// updates distance to obstacle
void ProximitySensor::update(const Robot &robot, const Terrain &terrain)
{
    // obtain direction of ray
    sf::Vector2f dir{cos(robot.get_direction() + angle_offset), sin(robot.get_direction() + angle_offset)};

    // get info about nearest object (if any) in direction
    distance_to_obstacle = terrain.cast_ray(robot.get_posn(), dir, Sensor::range);
}
