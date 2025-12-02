#pragma once

class Robot; // forward declaration
class Terrain;

// base sensor class: found in robot
// handles sensing of environment
class Sensor
{
public:
    float range; // sensor distance

    Sensor(float d);
    virtual void update(const Robot &robot, const Terrain &terrain) = 0;
    virtual ~Sensor() = default;
};