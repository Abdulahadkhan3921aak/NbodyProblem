#pragma once

#include <iostream>
#include <cmath>

struct vector2
{
    float x;
    float y;

    // Constructor
    vector2(float x = 0.0f, float y = 0.0f);

    // Arithmetic operators
    vector2 operator+(const vector2 &other) const;
    vector2 operator-(const vector2 &other) const;
    vector2 operator*(float scalar) const;
    vector2 operator/(float scalar) const;

    // Compound assignment
    vector2 &operator+=(const vector2 &other);
    vector2 &operator-=(const vector2 &other);
    vector2 &operator*=(float scalar);
    vector2 &operator/=(float scalar);

    // Comparison
    bool operator==(const vector2 &other) const;
    bool operator!=(const vector2 &other) const;

    // Vector math
    float dot(const vector2 &other) const;
    float cross(const vector2 &other) const;
    vector2 project(const vector2 &other) const;
    float magnitude() const;
    float distance(const vector2 &other) const;
    vector2 normalize() const;

    // Rotation
    vector2 rotate(float angle_rad) const;
    vector2 rotate(float angle_rad, const vector2 &origin) const;

    // Setters & Getters
    void set(float new_x, float new_y);
    void set_x(float new_x);
    void set_y(float new_y);
    float get_x() const;
    float get_y() const;

    // Debug
    void print() const;

    // Additional functions
    vector2 normalize(const vector2 &v);
    vector2 rotate(const vector2 &v, float angle_rad);
    vector2 rotate(const vector2 &v, float angle_rad, const vector2 &origin);

    // Destructor
    ~vector2();
};

// Stream operators
std::ostream &operator<<(std::ostream &os, const vector2 &v);
std::istream &operator>>(std::istream &is, vector2 &v);
// Additional functions
float distance(const vector2 &a, const vector2 &b);
float dot(const vector2 &a, const vector2 &b);
