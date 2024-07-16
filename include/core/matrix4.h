#ifndef MATRIX4_H
#define MATRIX4_H

#include <array>
#include <stdint.h>
#include <iostream>
#include <cmath>
#include "vector3.h"

class Matrix4{
private:

    std::array<float, 16> m_data;

public:

    Matrix4();

    void transpose();

    void identity();

    float& operator[](const int32_t & index);

    float determinant() const;

    void show() const;

    Matrix4 operator*(const Matrix4 & matrix) const;

    static Matrix4 translate(const Vector3 & translation);

    static Matrix4 scale(const Vector3 & scale);

    static Matrix4 rotate(const float & angle, const Vector3 & axis);

};

#endif
