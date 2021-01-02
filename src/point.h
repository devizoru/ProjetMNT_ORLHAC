#ifndef __POINT_H__
#define __POINT_H__

#include <cstdlib>
#include <fstream>
class Point
{
public:
    Point(float x, float y, float level);
    ~Point();

    friend std::istream &operator>>(std::istream &stream, Point &p);
    float m_x, m_y, m_level;
};

#endif