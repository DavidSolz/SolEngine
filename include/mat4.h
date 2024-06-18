#ifndef MAT4_H
#define MAT4_H

#include <array>
#include <stdint.h>
#include <iostream>
#include <cmath>
#include "vec3.h"

class Mat4{
private:

    std::array<float, 16> m_data;

public:

    Mat4();

    void transpose();

    void identity();

    float& operator[](const int32_t & index);

    float determinant() const;

    void show() const;

    Mat4 operator*(const Mat4 & matrix) const;

    static Mat4 translate(const Vec3 & translation);

    static Mat4 scale(const Vec3 & scale);

    static Mat4 rotate(const float & angle, const Vec3 & axis);

};

#endif
