#include "mat4.h"

Mat4::Mat4(){

    for(int32_t i = 0; i < 16; i++)
        m_data[i] = 0.0f;

    identity();
}

void Mat4::transpose(){

    for(int32_t i = 0; i < 4; i ++){
        for( int32_t j = i + 1; j < 4; j ++){
            float temp = m_data[i * 4 +j];
            m_data[i * 4 + j] = m_data[j*4+i];
            m_data[j*4+i] = temp;
        }
    }

}

void Mat4::identity(){

    m_data[0] = 1.0f;
    m_data[5] = 1.0f;
    m_data[10] = 1.0f;
    m_data[15] = 1.0f;

}

float& Mat4::operator[](const int32_t & index){
    uint32_t idx = std::max(0, std::min(index, 16));
    return m_data[idx];
}

Mat4 Mat4::operator*(const Mat4 & matrix) const{

    Mat4 result;

    for( int32_t i = 0; i < 4; i++ ){

        for( int32_t j = 0; j < 4; j++ ){

            float sum = 0.0f;

            for( int32_t k = 0; k < 4; k++ ){
                sum += m_data[i* 4 + k] * matrix.m_data[k *4 + j];
            }

            result.m_data[i * 4 + j] = sum;

        }

    }

    return result;
}

void Mat4::show() const{

    std::cout<<std::endl;

    for(int32_t i = 0; i < 4; i ++){
        for( int32_t j = 0; j < 4; j++){
            std::cout << m_data[i*4+j] << " ";
        }
        std::cout<<std::endl;
    }

}

float Mat4::determinant() const{

    float det1 = m_data[0] * m_data[5] - m_data[1] * m_data[4];
    float det2 = m_data[2] * m_data[7] - m_data[3] * m_data[6];
    float det3 = m_data[8] * m_data[13] - m_data[9] * m_data[12];
    float det4 = m_data[10] * m_data[15] - m_data[11] * m_data[14];

    float det = det1 * det4 - det2 * det3;

    return det;
}

Mat4 Mat4::translate(const Vec3 & translation){

    Mat4 result;

    result.m_data[0] = 1;
    result.m_data[3] = translation.x;
    result.m_data[5] = 1;
    result.m_data[7] = translation.y;
    result.m_data[10] = 1;
    result.m_data[11] = translation.z;
    result.m_data[15] = 1;

    return result;

}

Mat4 Mat4::scale(const Vec3 & scale){

    Mat4 result;

    result.m_data[0] = scale.x;
    result.m_data[5] = scale.y;
    result.m_data[10] = scale.z;
    result.m_data[15] = 1;

    return result;

}

Mat4 Mat4::rotate(const float & angle, const Vec3 & axis){

    Vec3 normalized = axis.normalize();

    constexpr float deg2rad = 3.1415926535f/180.0f;

    float angleInRad = angle * deg2rad;

    Mat4 result;

    float c = cos(angleInRad);
    float s = sin(angleInRad);

    result.m_data[0] = normalized.x * normalized.y * (1 - c) + c;
    result.m_data[1] = normalized.x * normalized.y * (1 - c) - s * normalized.z;
    result.m_data[2] = normalized.x * normalized.z * (1 - c) + s * normalized.y;

    result.m_data[4] = normalized.x * normalized.y * (1 - c) + s * normalized.z;
    result.m_data[5] = normalized.y * normalized.y * (1 - c) + c;
    result.m_data[6] = normalized.y * normalized.z * (1 - c) - s * normalized.x;

    result.m_data[8] = normalized.x * normalized.z * (1 - c) - s * normalized.y;
    result.m_data[9] = normalized.y * normalized.z * (1 - c) + s * normalized.x;
    result.m_data[10] = normalized.z * normalized.z * (1 - c) + c;

    return result;
}
