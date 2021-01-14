#include "point.h"

Point::Point(float x, float y, float level) : m_x(x), m_y(y), m_level(level)
{
}

Point::~Point()
{
    // Nothing to destroy.
}

void Point::latlong2lambert93(std::vector<Point> &Points)
{
    // PJ_CONTEXT *C;
    // PJ *P;
    // PJ *P_for_GIS;
    // PJ_COORD a, b;

    // C = proj_context_create();

    // P = proj_create_crs_to_crs(C,
    //                            "EPSG:4326",
    //                            "EPSG:2154",
    //                            NULL);

    // if (0 == P)
    // {
    //     fprintf(stderr, "Oops\n");
    //     return;
    // }

    // P_for_GIS = proj_normalize_for_visualization(C, P);
    // if (0 == P_for_GIS)
    // {
    //     fprintf(stderr, "Oops\n");
    //     return;
    // }

    // proj_destroy(P);
    // P = P_for_GIS;

    // for (std::size_t i = 0; i < Points.size(); i++)
    // {
    //     a = proj_coord(Points.at(i).m_y, Points.at(i).m_x, 0, 0);

    //     b = proj_trans(P, PJ_FWD, a);
    //     printf("easting: %.3f, northing: %.3f\n", b.enu.e, b.enu.n);

    //     Points.at(i).m_y = b.xy.x;
    //     Points.at(i).m_x = b.xy.x;
    // }

    // proj_destroy(P);
    // proj_context_destroy(C); /* may be omitted in the single threaded case */
}

std::istream &operator>>(std::istream &stream, Point &p)
{
    stream >> p.m_x;
    stream >> p.m_y;
    stream >> p.m_level;
    return stream;
}