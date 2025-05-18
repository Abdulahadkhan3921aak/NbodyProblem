#include "initializeBody.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "body.h"

std::vector<body> initializeBodies(const std::string &filename, float scale, float radiusScale)
{
    std::vector<body> bodies;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return bodies;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name;
        float x, y, vx, vy, mass, radius, color;
        char comma;

        std::getline(ss, name, ',');
        ss >> x >> comma >> y >> comma >> vx >> comma >> vy >> comma >> mass >> comma >> radius >> comma >> color;

        vector2 position(x * scale, y * scale);
        vector2 velocity(vx * scale, vy * scale);
        vector2 acceleration(0.0f, 0.0f);
        vector2 force(0.0f, 0.0f);
        float size = radius * radiusScale;

        bodies.emplace_back(name, position, velocity, acceleration, mass, force, size, color, radius);
    }

    file.close();

    for (const auto &b : bodies)
    {
        std::cout << "Body: " << b.get_name()
                  << ", Pos: (" << b.get_x() << ", " << b.get_y() << ")"
                  << ", Vel: (" << b.get_vx() << ", " << b.get_vy() << ")"
                  << ", Mass: " << b.get_mass()
                  << ", Radius: " << b.get_radius()
                  << std::endl;
    }

    return bodies;
}
