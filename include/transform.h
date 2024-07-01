#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3.h"
#include "matrix4.h"

class Transform {

private:
    Vector3 m_position = {0.0f, 0.0f, 0.0f};
    Vector3 m_rotation = {0.0f, 0.0f, 0.0f};
    Vector3 m_scale = {1.0f, 1.0f, 1.0f};

    Matrix4 m_modelMatrix = Matrix4();

    bool m_isDirty = false;

    Matrix4 getLocalModelMatrix();

public:

    void computeModelMatrix();

    void computeModelMatrix(const Matrix4 & parentMatrix);

    void setLocalPosition(const Vector3 & position);

    void setLocalRotation(const Vector3 & rotation);

    void setLocalScale(const Vector3 & scale);

    Vector3& getLocalPosition();

    Vector3& getLocalRotation();

    Vector3& getLocalScale();

    Matrix4& getModelMatrix();

    bool isDirty() const;

};

#endif
