#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <cstdlib>
#include <fstream>
class Image
{
public:
    Image(int w, int h, uint8_t *pixels);
    ~Image();

    int m_w, m_h;
    uint8_t *m_pixels;

    void export_image(const std::string &filename);
};

#endif