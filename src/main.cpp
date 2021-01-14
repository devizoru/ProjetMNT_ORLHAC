#include <cstdlib>
#include <iostream>
#include "generator.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
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
