#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class Vec3{
public:

    float x;
    float y;
    float z;

    Vec3 normalize() const;

    float magnitude() const;

    float magnitudeSqr() const;

    float dotProduct(const Vec3 & vector) const;

};

#endif
