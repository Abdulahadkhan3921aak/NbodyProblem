#pragma once
#include <iostream>
#include <cmath>

struct vector3
{
    float x;
    float y;
    float z;

    // Constructor
    vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    // Arithmetic operators
    vector3 operator+(const vector3 &other) const;
    vector3 operator-(const vector3 &other) const;
    vector3 operator*(float scalar) const;
    vector3 operator/(float scalar) const;

    // Compound assignment
    vector3 &operator+=(const vector3 &other);
    vector3 &operator-=(const vector3 &other);
    vector3 &operator*=(float scalar);
    vector3 &operator/=(float scalar);

    // Comparison
    bool operator==(const vector3 &other) const;
    bool operator!=(const vector3 &other) const;

    // Vector math
    float dot(const vector3 &other) const;
    float cross(const vector3 &other) const;
    vector3 project(const vector3 &other) const;
    float magnitude() const;
    float distance(const vector3 &other) const;
    vector3 normalize() const;

    // Rotation
    vector3 rotate(float angle_rad) const;
    vector3 rotate(float angle_rad, const vector3 &origin) const;

    // Setters & Getters
    void set(float new_x, float new_y, float new_z);
    void set_x(float new_x);
    void set_y(float new_y);
    void set_z(float new_y);
    float get_x() const;
    float get_y() const;
    float get_z() const;

    // Debug
    void print() const;

    // Additional functions
    vector3 normalize(const vector3 &v);
    vector3 rotate(const vector3 &v, float angle_rad);
    vector3 rotate(const vector3 &v, float angle_rad, const vector3 &origin);

    // Destructor
    ~vector3();
};

// Stream operators
std::ostream &operator<<(std::ostream &os, const vector3 &v);
std::istream &operator>>(std::istream &is, vector3 &v);
// Additional functions
float distance(const vector3 &a, const vector3 &b);
float dot(const vector3 &a, const vector3 &b);
