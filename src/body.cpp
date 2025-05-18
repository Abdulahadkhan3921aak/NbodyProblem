#include "body.h"
// body.cpp
body::body(std::string name, vector2 pos, vector2 vel, vector2 acc, double m, vector2 f, double s, float c, double r)
    : name(name), position(pos), velocity(vel), acceleration(acc),
      mass(m), force(f), size(s), color(c), radius(r)
{
}

// Setters
void body::set_name(std::string name)
{
    this->name = name;
}

void body::set_position(vector2 pos)
{
    this->position = pos;
}
void body::set_velocity(vector2 vel)
{
    this->velocity = vel;
}
void body::set_acceleration(vector2 acc)
{
    this->acceleration = acc;
}
void body::set_mass(double m)
{
    this->mass = m;
}
void body::set_force(vector2 f)
{
    this->force = f;
}
void body::set_size(double s)
{
    this->size = s;
}
void body::set_color(float c)
{
    this->color = c;
}
void body::set_radius(double r)
{
    this->radius = r;
}

// Getters
std::string body::get_name() const
{
    return this->name;
}

vector2 body::get_position() const
{
    return this->position;
}
vector2 body::get_velocity() const
{
    return this->velocity;
}
vector2 body::get_acceleration() const
{
    return this->acceleration;
}
double body::get_mass() const
{
    return this->mass;
}
vector2 body::get_force() const
{
    return this->force;
}
double body::get_size() const
{
    return this->size;
}
float body::get_color() const
{
    return this->color;
}
double body::get_radius() const
{
    return this->radius;
}

float body::get_x() const
{
    return this->position.get_x();
}
float body::get_y() const
{
    return this->position.get_y();
}
float body::get_vx() const
{
    return this->velocity.get_x();
}
float body::get_vy() const
{
    return this->velocity.get_y();
}
float body::get_ax() const
{
    return this->acceleration.get_x();
}
float body::get_ay() const
{
    return this->acceleration.get_y();
}

float body::get_fx() const
{
    return this->force.get_x();
}
float body::get_fy() const
{
    return this->force.get_y();
}

// Destructor
// The destructor is automatically called when an object of this class goes out of scope

body::~body()
{
    // Destructor
    // Clean up resources if needed
    // In this case, we don't have any dynamic memory allocation
    // so we don't need to do anything here
    // But if we had pointers or dynamic arrays, we would free them here
}