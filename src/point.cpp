#include "point.h"
#include <iostream>

using namespace std;
Point::Point(float x, float y, float level) : m_x(x), m_y(y), m_level(level)
{
}

Point::~Point()
{
    // Nothing to destroy.
}
istream &operator>>(istream &stream, Point &p)
{
    stream >> p.m_x;
    stream >> p.m_y;
    stream >> p.m_level;
    return stream;
}