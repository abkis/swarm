#pragma once
#include "sensor.h"
#include <vector>

class Robot;
class Terrain;

// senses neighboring robots within a specific radius
// updates them with any new info
class NeighborSensor : public Sensor
{
    std::vector<Robot *> neighbors;

public:
    NeighborSensor(float range);
    void update(const Robot &robot, const Terrain &terrain) override;

    inline std::vector<Robot *> get_neighbors() const { return neighbors; };
};