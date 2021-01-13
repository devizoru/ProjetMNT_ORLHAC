#ifndef __POINT_H__
#define __POINT_H__

#include <cstdlib>
#include <iostream>
#include "../lib/proj/src/proj.h"
#include "point.h"
#include <vector>
#include <fstream>

class Point
{
public:
    Point(float x, float y, float level);
    ~Point();

    friend std::istream &operator>>(std::istream &stream, Point &p);
    float m_x, m_y, m_level;
    void latlong2lambert93(std::vector<Point> &Points);
};

#endif