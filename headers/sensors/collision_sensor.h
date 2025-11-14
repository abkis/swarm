#include "sensor.h"

// detects collision: location, force, magnitude
class CollisionSensor : public Sensor
{
    sf::Vector2f force{0, 0}; // vector of force exerted by collision
    sf::Vector2f posn{0, 0};  // position of collision in xy plane
    bool collision{false};    // set to true if collision occured
public:
    CollisionSensor();
    void update(const Robot &robot, const Terrain &terrain) override;
};