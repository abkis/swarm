#include "sensors/neighbor_sensor.h"
#include <cmath>
#include "objects/robots/robot.h"

NeighborSensor::NeighborSensor(float range) : Sensor(range) {}

// called on robot movement
// senses environment and determines if any robots around
// updates robots
void NeighborSensor::update(const Robot &robot, const Terrain &terrain)
{
    // obtain vector of robots
    neighbors = terrain.find_neighbors(robot.get_posn(), Sensor::range);
}
