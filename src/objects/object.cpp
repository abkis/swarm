#include "objects/object.h"
#include "helpers.h"

Object::Object(const sf::Vector2f &posn, const sf::Vector2f &size, const sf::Color color) : posn{posn}, size{size}

{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

Object::Object(const Object &obs) : posn{obs.get_posn()}, size{obs.get_size()}, shape{obs.get_shape()} {}

Object::Object(float x, float y, float w, float h, sf::Color color) : posn{x, y}, size{w, h}
{
    shape.setSize(size);
    shape.setPosition(posn);
    shape.setFillColor(color);
}

bool Object::at_posn(const sf::RectangleShape test_shape) const
{
    return shape.getGlobalBounds().intersects(test_shape.getGlobalBounds());
}

// determine if vector from posn in direction dir with length range intersects object
bool Object::at_posn(const sf::Vector2f posn, const sf::Vector2f dir, const float range) const
{
    if (helpers::mag(dir) == 0)
    {
        return false; // nothing to check
    }
    sf::Vector2f unit = helpers::normalize(dir); // unit direction vector
    // line segment is l(t) = posn + t*unit for 0 <= t <= range
    // use slab method since assuming rectangular shape
    // TODO: update if use other shapes

    sf::FloatRect bounds = shape.getGlobalBounds();
    float tmin = 0.0f;
    float tmax = range;

    // check x-slab
    float x = bounds.left;
    if (dir.x < 1e-6f)
    {
        // x direction small so division wouldn't work
        if (posn.x < x || posn.x > x + bounds.width)
        {
            // no intersection
            return false;
        }
    }
    else
    {
        // division is ok
        float t1 = (x - posn.x) / dir.x;
        float t2 = (x + bounds.width - posn.x) / dir.x;
        tmin = std::max(tmin, std::min(t1, t2));
        tmax = std::min(tmax, std::max(t1, t2));
        if (tmin > tmax)
        {
            return false;
        }
    }

    // repeat for y
    // sfml has origin in top left corner, lower down => higher y-val
    float y = bounds.top; // top of rect so need posn to be between this and y+bounds.height
    if (dir.y < 1e-6f)
    {
        // y direction small so division wouldn't work
        if (posn.y < y || posn.y > y + bounds.height)
        {
            // no intersection
            return false;
        }
    }
    else
    {
        // division is ok
        float t1 = (y - posn.y) / dir.y;                 // min y-val
        float t2 = (y + bounds.height - posn.y) / dir.y; // max y-vl
        tmin = std::max(tmin, std::min(t1, t2));
        tmax = std::min(tmax, std::max(t1, t2));
        if (tmin > tmax)
        {
            return false;
        }
    }
    return (tmin >= 0 && tmin <= range);
}
