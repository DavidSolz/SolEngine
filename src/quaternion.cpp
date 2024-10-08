#include "quaternion.h"

Quaternion::Quaternion(const float &x, const float &y, const float &z, const float &w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Quaternion::Quaternion()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
    this->w = 1.0f;
}

float Quaternion::Magnitude() const
{
    return sqrtf(x * x + y * y + z * z);
}

float Quaternion::Dot(const Quaternion &a, const Quaternion &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Quaternion Quaternion::Normalize()
{
    float magnitude = this->Magnitude();

    if (magnitude <= 1e-6f)
        magnitude = 1.0f;

    return Quaternion(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
}

Quaternion Quaternion::ToQuaternion(const Vector3 &euler)
{

    Quaternion q;

    float cr = cos(euler.x * 0.5);
    float sr = sin(euler.x * 0.5);
    float cp = cos(euler.y * 0.5);
    float sp = sin(euler.y * 0.5);
    float cy = cos(euler.z * 0.5);
    float sy = sin(euler.z * 0.5);

    q.w = cr * cp * cy + sr * sp * sy;
    q.x = sr * cp * cy - cr * sp * sy;
    q.y = cr * sp * cy + sr * cp * sy;
    q.z = cr * cp * sy - sr * sp * cy;

    return q;
}

Vector3 Quaternion::ToEulerAngles(const Quaternion &q)
{
    Vector3 angles;

    // roll (x-axis rotation)
    float sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    float cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    angles.x = atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    float sinp = sqrtf(1 + 2 * (q.w * q.y - q.x * q.z));
    float cosp = sqrtf(1 - 2 * (q.w * q.y - q.x * q.z));
    angles.y = 2 * atan2(sinp, cosp) - 3.1415926535f / 2;

    // yaw (z-axis rotation)
    float siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    float cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    angles.z = atan2(siny_cosp, cosy_cosp);

    return angles;
}

Quaternion Quaternion::operator+(const Quaternion &q) const
{
    return Quaternion(x + q.x, y + q.y, z + q.z, w + q.w);
}

Quaternion Quaternion::operator-(const Quaternion &q) const
{
    return Quaternion(x - q.x, y - q.y, z - q.z, w - q.w);
}

Quaternion Quaternion::operator*(const Quaternion &q) const
{
    return Quaternion(
        w * q.w - x * q.x - y * q.y - z * q.z,
        w * q.x + x * q.w + y * q.z - z * q.y,
        w * q.y - x * q.z + y * q.w + z * q.x,
        w * q.z + x * q.y - y * q.x + z * q.w);
}
