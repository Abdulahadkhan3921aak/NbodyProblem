#include "vector3.h"
#include <cmath>
#include <iostream>

// Constructor
vector3::vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

// Arithmetic operators
vector3 vector3::operator+(const vector3 &other) const
{
    return vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

vector3 vector3::operator-(const vector3 &other) const
{
    return vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

vector3 vector3::operator*(float scalar) const
{
    return vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}

vector3 vector3::operator/(float scalar) const
{
    if (scalar != 0)
    {
        return vector3(this->x / scalar, this->y / scalar, this->z / scalar);
    }
    else
    {
        std::cerr << "Error: Division by zero in vector3 operator/." << std::endl;
        return vector3(0, 0, 0); // Return a zero vector or handle the error as needed
    }
}

// Compound assignment
vector3 &vector3::operator+=(const vector3 &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

vector3 &vector3::operator-=(const vector3 &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

vector3 &vector3::operator*=(float scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

vector3 &vector3::operator/=(float scalar)
{
    if (scalar != 0)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
    }
    else
    {
        std::cerr << "Error: Division by zero in vector3 operator/=" << std::endl;
        // Handle the error as needed
    }
    return *this;
}

// Comparison
bool vector3::operator==(const vector3 &other) const
{
    return (this->x == other.x && this->y == other.y && this->z == other.z);
}

bool vector3::operator!=(const vector3 &other) const
{
    return !(*this == other);
}

// Vector math
float vector3::dot(const vector3 &other) const
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

float vector3::cross(const vector3 &other) const
{
    return this->x * other.y - this->y * other.x;
}

vector3 vector3::project(const vector3 &other) const
{
    float scalar = this->dot(other) / other.dot(other);
    return other * scalar;
}

float vector3::magnitude() const
{
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

float vector3::distance(const vector3 &other) const
{
    return std::sqrt((this->x - other.x) * (this->x - other.x) +
                     (this->y - other.y) * (this->y - other.y) +
                     (this->z - other.z) * (this->z - other.z));
}

vector3 vector3::normalize() const
{
    float mag = this->magnitude();
    if (mag != 0)
    {
        return vector3(this->x / mag, this->y / mag, this->z / mag);
    }
    else
    {
        std::cerr << "Error: Cannot normalize a zero vector." << std::endl;
        return vector3(0, 0, 0); // Return a zero vector or handle the error as needed
    }
}
// Rotation
vector3 vector3::rotate(float angle_rad) const
{
    float cos_angle = std::cos(angle_rad);
    float sin_angle = std::sin(angle_rad);
    return vector3(this->x * cos_angle - this->y * sin_angle, this->x * sin_angle + this->y * cos_angle, this->z);
}

vector3 vector3::rotate(float angle_rad, const vector3 &origin) const
{
    vector3 translated = *this - origin;
    float cos_angle = std::cos(angle_rad);
    float sin_angle = std::sin(angle_rad);
    return vector3(translated.x * cos_angle - translated.y * sin_angle,
                   translated.x * sin_angle + translated.y * cos_angle,
                   translated.z) +
           origin;
}

// Setters & Getters
void vector3::set(float new_x, float new_y, float new_z)
{
    this->x = new_x;
    this->y = new_y;
    this->z = new_z;
}

void vector3::set_x(float new_x)
{
    this->x = new_x;
}

void vector3::set_y(float new_y)
{
    this->y = new_y;
}

void vector3::set_z(float new_z)
{
    this->z = new_z;
}

float vector3::get_x() const
{
    return this->x;
}

float vector3::get_y() const
{
    return this->y;
}

float vector3::get_z() const
{
    return this->z;
}

// Debug
void vector3::print() const
{
    std::cout << "vector3(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
}

// Stream operators
std::ostream &operator<<(std::ostream &os, const vector3 &v)
{
    os << "vector3(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::istream &operator>>(std::istream &is, vector3 &v)
{
    is >> v.x >> v.y >> v.z;
    return is;
}

// Additional functions
float distance(const vector3 &a, const vector3 &b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) +
                     (a.y - b.y) * (a.y - b.y) +
                     (a.z - b.z) * (a.z - b.z));
}

float dot(const vector3 &a, const vector3 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector3::~vector3()
{
    // Destructor
    // Clean up resources if needed
    // In this case, we don't have any dynamic memory allocation
    // so we don't need to do anything here
    // But if we had pointers or dynamic arrays, we would free them here
}