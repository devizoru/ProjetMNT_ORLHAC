#include "image.h"
#include <iostream>

using namespace std;
Image::Image(int w, int h, uint8_t *pixels) : m_w(w), m_h(h), m_pixels(pixels)
{
}

Image::~Image()
{
    // Nothing to destroy.
}

void Image::export_image(const std::string &filename)
{
    ofstream image(filename);
    if (!image.is_open())
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier en lecture");
    }
    image << "P6" << endl;
    image << m_w << " " << m_h << " "
          << "255" << endl;
    image.write((char *)m_pixels, m_w * m_h * 3);
    image.close();
}