#include "generator.h"
#include <iostream>
#include <vector>
#include "point.h"
#include "image.h"
#include "math.h"

using namespace std;
Generator::Generator(size_t w, size_t h, std::string filename) : m_w(w), m_h(h), m_filename(filename)
{
}

Generator::~Generator()
{
    // Nothing to destroy.
}

void Generator::generate()
{
    vector<Point> points;
    ifstream f(m_filename);

    if (!f.is_open())
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier en lecture");
    }
    while (!f.eof()) // eof: end of file
    {
        Point p(0, 0, 0);
        f >> p;
        // cout << p.m_x << " " << p.m_y << " " << p.m_level << endl;
        points.push_back(p);
    }
    f.close();

    // TODO: projection using PROJ

    float lat_min, lat_max, lon_min, lon_max, lv_min, lv_max;

    lat_min = lat_max = points[0].m_x;
    lon_min = lon_max = points[0].m_y;
    lv_min = lv_max = points[0].m_level;

    // Find minimum & maximum
    for (std::size_t i = 0; i < points.size(); i++)
    {
        if (points[i].m_x < lat_min)
        {
            lat_min = points[i].m_x;
        }
        if (points[i].m_x > lat_max)
        {
            lat_max = points[i].m_x;
        }
        if (points[i].m_y < lon_min)
        {
            lon_min = points[i].m_y;
        }
        if (points[i].m_y > lon_max)
        {
            lon_max = points[i].m_y;
        }
        if (points[i].m_level < lv_min)
        {
            lv_min = points[i].m_level;
        }
        if (points[i].m_level > lv_max)
        {
            lv_max = points[i].m_level;
        }
    }

    uint8_t *image_data = new uint8_t[m_w * m_h * 3];
    //Initialize all pixels to level zero to reset memory in case there is information remaining
    for (size_t i = 0; i < m_w * m_h * 3; i++)
    {
        image_data[i] = 0;
    }

    // Mapping pixels and setting level of each pixel
    for (size_t i = 0; i < points.size(); i++)
    {
        size_t x, y;
        Point point = points[i];

        x = (point.m_x - lat_min) / (lat_max - lat_min) * m_w;
        y = (point.m_y - lon_min) / (lon_max - lon_min) * m_h;

        size_t image_index = x * 3 + y * m_w * 3;
        uint8_t level = 255 - (point.m_level - lv_min) / (lv_max - lv_min) * 255;

        if (level > image_data[image_index])
        {
            image_data[image_index] = level;
        }
    }

    uint8_t colormap[] = {
        37, 57, 175,
        40, 127, 251,
        50, 190, 255,
        106, 235, 255,
        138, 236, 174,
        205, 255, 162,
        240, 236, 121,
        255, 189, 87,
        255, 161, 68,
        255, 186, 133,
        255, 255, 255};

    // Coloring pixels according to level, by interpolating RGB data from the Haxby colormap
    for (size_t i = 0; i < m_w * m_h * 3; i += 3)
    {
        float colormap_index = ((float)image_data[i]) / 255 * 11;
        float alpha = colormap_index - floor(colormap_index);
        float a = floor(colormap_index);
        float b = ceil(colormap_index);

        image_data[i] = colormap[((size_t)a) * 3] * (1 - alpha) + colormap[((size_t)b) * 3] * alpha;
        image_data[i + 1] = colormap[((size_t)a) * 3 + 1] * (1 - alpha) + colormap[((size_t)b) * 3 + 1] * alpha;
        image_data[i + 2] = colormap[((size_t)a) * 3 + 2] * (1 - alpha) + colormap[((size_t)b) * 3 + 2] * alpha;
    }

    Image image(m_w, m_h, image_data);
    image.export_image("../mnt.ppm");
}