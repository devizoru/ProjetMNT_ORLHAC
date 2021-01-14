#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <cstdlib>
#include <fstream>
class Generator
{
public:
    Generator(size_t w, size_t h, std::string filename);
    ~Generator();

    size_t m_w, m_h;
    std::string m_filename;

    void generate();
};

#endif