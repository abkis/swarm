#pragma once
#include "sensors/sensor.h"
#include "sensors/neighbor_sensor.h"
#include "objects/object.h"
#include "terrain.h"
#include <memory>

class Sensor;
class Terrain;
class NeighborSensor;

// base class for robot; simplest kind
class Robot : public Object
{
    sf::Vector2f vel;       // velocity of movement in x/y direction
    const float max_speed;  // speed of max movement
    const float speed_incr; // amount magnitude of velocity can increase by per time step
    const int id;           // unique id

    float direction{0}; // direction robot is moving in, in radians
    float mass{1};
    std::vector<std::unique_ptr<Sensor>> sensors;

    void on_collision(sf::Vector2f force);      // handles when robot collides with something
    void check_collision();                     // checks if robot collided with something
    void update_sensor(const Terrain &terrain); // update sensors after movement
    void increase_speed();                      // increase robot speed (if possible)

public:
    Robot(float v_x, float v_y, float p_x, float p_y, float size_x, float size_y, float direction, float mass, float max_speed, float speed_incr, int id, sf::Color color = sf::Color::Black);
    void random_movement();                          // move in random manner
    void add_sensor(std::unique_ptr<Sensor> sensor); // add new sensor

    inline float get_direction() const { return direction; };
    inline sf::Vector2f get_vel() const { return vel; };
    inline float get_mass() const { return mass; }
    inline int get_id() const { return id; }

    void update(const Sensor &sensor, const Terrain &terrain); // update robot info using sensor
    void update_from_robot(const Robot &robot);                // update robot info from another robot

    void transmit_info(const std::weak_ptr<NeighborSensor> sensor) const; // transmit info to neighbors
};