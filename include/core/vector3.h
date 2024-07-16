#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3{
public:

    float x;
    float y;
    float z;

    Vector3() = default;

    Vector3(const float & x, const float & y, const float & z);

    Vector3 normalize() const;

    float magnitude() const;

    float magnitudeSqr() const;

    float dotProduct(const Vector3 & vector) const;

    Vector3 operator+(const Vector3 & b);

    Vector3 operator-(const Vector3 & b);

    Vector3 operator*(const Vector3 & b);

};

#endif
