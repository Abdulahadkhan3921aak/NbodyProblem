#pragma once

#include <vector2.h>
#include <cmath>
#include <omp.h>
#include <string>

class body
{
private:
    /* data */
    std::string name; // name of the body
    vector2 position;
    vector2 velocity;
    vector2 acceleration;
    double mass;
    vector2 force;
    double size;   // on screen size
    float color;   // color on screen
    double radius; // radius of the body

public:
    body(std::string name, vector2 pos, vector2 vel, vector2 acc, double m, vector2 f, double s, float c, double r);
    ~body();

    // Setters
    void set_name(std::string name);
    void set_position(vector2 pos);
    void set_velocity(vector2 vel);
    void set_acceleration(vector2 acc);
    void set_mass(double m);
    void set_force(vector2 f);
    void set_size(double s);
    void set_color(float c);
    void set_radius(double r);

    // Getters
    std::string get_name() const;
    vector2 get_position() const;
    vector2 get_velocity() const;
    vector2 get_acceleration() const;
    double get_mass() const;
    vector2 get_force() const;
    double get_size() const;
    float get_color() const;
    double get_radius() const;
    float get_x() const;
    float get_y() const;
    float get_vx() const;
    float get_vy() const;
    float get_ax() const;
    float get_ay() const;
    float get_fx() const;
    float get_fy() const;
};
