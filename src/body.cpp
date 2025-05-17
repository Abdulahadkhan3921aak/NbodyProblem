#include "body.h"
// body.cpp
body::body(vector2 pos, vector2 vel, vector2 acc, vector2 m, vector2 f, float s, float c, vector2 r)
{
    this->position = pos;
    this->velocity = vel;
    this->acceleration = acc;
    this->mass = m;
    this->force = f;
    this->size = s;
    this->color = c;
    this->radius = r;
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
void body::set_mass(vector2 m)
{
    this->mass = m;
}
void body::set_force(vector2 f)
{
    this->force = f;
}
void body::set_size(float s)
{
    this->size = s;
}
void body::set_color(float c)
{
    this->color = c;
}
void body::set_radius(vector2 r)
{
    this->radius = r;
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