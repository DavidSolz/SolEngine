#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>
#include "vector3.h"

class Quaternion{
private:

    float Magnitude() const;

public:

    float x;
    float y;
    float z;
    float w;

    Quaternion();

    Quaternion(const float & x, const float & y, const float & z, const float & w);

    Quaternion Normalize();

    static float Dot(const Quaternion & a, const Quaternion & b);

    static Quaternion ToQuaternion(const Vector3 & euler);

    static Vector3 ToEulerAngles(const Quaternion & q);

    Quaternion operator+(const Quaternion & q) const;

    Quaternion operator-(const Quaternion & q) const;

    Quaternion operator*(const Quaternion& q) const;

};

#endif
