#include "vector2.h"
#include <cmath>
#include <iostream>

// Constructor
vector2::vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

// Arithmetic operators
vector2 vector2::operator+(const vector2 &other) const
{
    return vector2(this->x + other.x, this->y + other.y);
}
vector2 vector2::operator-(const vector2 &other) const
{
    return vector2(this->x - other.x, this->y - other.y);
}
vector2 vector2::operator*(float scalar) const
{
    return vector2(this->x * scalar, this->y * scalar);
}
vector2 vector2::operator/(float scalar) const
{
    if (scalar != 0)
    {
        return vector2(this->x / scalar, this->y / scalar);
    }
    else
    {
        std::cerr << "Error: Division by zero in vector2 operator/." << std::endl;
        return vector2(0, 0); // Return a zero vector or handle the error as needed
    }
}
// Compound assignment
vector2 &vector2::operator+=(const vector2 &other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}
vector2 &vector2::operator-=(const vector2 &other)
{
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}
vector2 &vector2::operator*=(float scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}
vector2 &vector2::operator/=(float scalar)
{
    if (scalar != 0)
    {
        this->x /= scalar;
        this->y /= scalar;
    }
    else
    {
        std::cerr << "Error: Division by zero in vector2 operator/=" << std::endl;
    }
    return *this;
}
// Comparison
bool vector2::operator==(const vector2 &other) const
{
    return (this->x == other.x && this->y == other.y);
}
bool vector2::operator!=(const vector2 &other) const
{
    return !(*this == other);
}
// Vector math
float vector2::dot(const vector2 &other) const
{
    return (this->x * other.x + this->y * other.y);
}
float vector2::cross(const vector2 &other) const
{
    return (this->x * other.y - this->y * other.x);
}
vector2 vector2::project(const vector2 &other) const
{
    float scalar = this->dot(other) / other.dot(other);
    return other * scalar;
}
float vector2::magnitude() const
{
    return std::sqrt(this->x * this->x + this->y * this->y);
}
float vector2::distance(const vector2 &other) const
{
    return std::sqrt((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
}
vector2 vector2::normalize() const
{
    float mag = this->magnitude();
    if (mag != 0)
    {
        return vector2(this->x / mag, this->y / mag);
    }
    else
    {
        std::cerr << "Error: Cannot normalize a zero vector." << std::endl;
        return vector2(0, 0); // Return a zero vector or handle the error as needed
    }
}

// Rotation
vector2 vector2::rotate(float angle_rad) const
{
    float cos_angle = std::cos(angle_rad);
    float sin_angle = std::sin(angle_rad);
    return vector2(this->x * cos_angle - this->y * sin_angle, this->x * sin_angle + this->y * cos_angle);
}
vector2 vector2::rotate(float angle_rad, const vector2 &origin) const
{
    vector2 translated = *this - origin;
    float cos_angle = std::cos(angle_rad);
    float sin_angle = std::sin(angle_rad);
    return vector2(translated.x * cos_angle - translated.y * sin_angle, translated.x * sin_angle + translated.y * cos_angle) + origin;
}
// Setters & Getters
void vector2::set(float new_x, float new_y)
{
    this->x = new_x;
    this->y = new_y;
}
void vector2::set_x(float new_x)
{
    this->x = new_x;
}
void vector2::set_y(float new_y)
{
    this->y = new_y;
}
float vector2::get_x() const
{
    return this->x;
}
float vector2::get_y() const
{
    return this->y;
}
// Debug
void vector2::print() const
{
    std::cout << "vector2(" << this->x << ", " << this->y << ")" << std::endl;
}
// Stream operators
std::ostream &operator<<(std::ostream &os, const vector2 &v)
{
    os << "vector2(" << v.x << ", " << v.y << ")";
    return os;
}
std::istream &operator>>(std::istream &is, vector2 &v)
{
    is >> v.x >> v.y;
    return is;
}
// Additional functions
float distance(const vector2 &a, const vector2 &b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
float dot(const vector2 &a, const vector2 &b)
{
    return (a.x * b.x + a.y * b.y);
}

// Destructor
// The destructor is automatically called when an object of this class goes out of scope
vector2::~vector2()
{
    // Destructor
    // Clean up resources if needed
    // In this case, we don't have any dynamic memory allocation
    // so we don't need to do anything here
    // But if we had pointers or dynamic arrays, we would free them here
}