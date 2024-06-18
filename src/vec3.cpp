#include "vec3.h"

Vec3 Vec3::normalize() const{

    float len = magnitude();
    if( len < 1e-6f )
        len = 1.0f;

    return (Vec3){x/len, y/len, z/len};
}

float Vec3::magnitude() const{
    return std::sqrtf(magnitudeSqr());
}

float Vec3::magnitudeSqr() const{
    return x*x + y*y + z*z;
}

float Vec3::dotProduct(const Vec3 & vector) const{
    return x*vector.x + y * vector.y + z * vector.z;
}
