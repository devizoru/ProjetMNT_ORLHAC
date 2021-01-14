#include <cstdlib>
#include <iostream>
#include "generator.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        // Execution requires the name of the file to decode and turn into a ppm file, as well as a dimension
        std::cerr << "Missing arguments" << std::endl;
    }
    else
    {
        std::string filename(argv[1]);
        size_t dimensions = std::stoi(argv[2]);
        // std::cout << filename << std::endl;
        // std::cout << dimensions << std::endl;

        Generator generator(dimensions, dimensions, filename);
        generator.generate();
    }
}
