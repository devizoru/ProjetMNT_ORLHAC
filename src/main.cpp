#include <cstdlib>
#include <iostream>
#include "../lib/proj/src/proj.h"
#include "point.h"
#include <vector>
#include "image.h"

using namespace std;

vector<Point> lecture_MNT(const string &file_name)
{
    vector<Point> points;
    ifstream f(file_name);

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
    cout << "Completed" << endl;
    return points;
}

int main()
{
    // auto points = lecture_MNT("../Donnees.txt");

    uint8_t *image_data = new uint8_t[256 * 256 * 3];

    Image image(256, 256, image_data);
    image.export_image("../mnt.ppm");
}
