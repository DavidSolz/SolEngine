#include "vector3.h"


Vector3::Vector3(const float & x, const float & y, const float & z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3 Vector3::normalize() const{

    float len = magnitude();
    if( len < 1e-6f )
        len = 1.0f;

    return (Vector3){x/len, y/len, z/len};
}

float Vector3::magnitude() const{
    return std::sqrt(magnitudeSqr());
}

float Vector3::magnitudeSqr() const{
    return x*x + y*y + z*z;
}

float Vector3::dotProduct(const Vector3 & vector) const{
    return x*vector.x + y * vector.y + z * vector.z;
}

Vector3 Vector3::operator+(const Vector3 & b){
    return Vector3(x + b.x, y + b.y, z + b.z);
}

Vector3 Vector3::operator-(const Vector3 & b){
    return Vector3(x - b.x, y - b.y, z - b.z);
}

Vector3 Vector3::operator*(const Vector3 & b){
    return Vector3(x * b.x, y * b.y, z * b.z);
}
