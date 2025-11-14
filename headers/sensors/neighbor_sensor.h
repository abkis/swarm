#pragma once
#include "sensor.h"

// senses neighboring robots within a specific radius
// updates them with any new info
class NeighborSensor : public Sensor
{
    std::vector<std::weak_ptr<Robot>> neighbors;

public:
    NeighborSensor(float range);
    void update(const Robot &robot, const Terrain &terrain) override;

    inline std::vector<std::weak_ptr<Robot>> get_neighbors() const { return neighbors; };
};