#pragma once
#include "sensor.h"

// child class of Sensor
// detects proximity of objects without contact
// can see distance sensor.range ahead and at an angle angle_offset wrt current robot position
class ProximitySensor : public Sensor
{
    float angle_offset{0};
    float distance_to_obstacle{-1}; // if distance < 0 implies no object can be seen

public:
    ProximitySensor(float range, float angle);
    void update(const Robot &robot, const Terrain &terrain) override;

    inline float get_dist_to_obs() const { return distance_to_obstacle; };
};