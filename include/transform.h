#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "component.h"
#include "quaternion.h"
#include "matrix4.h"

class Transform : public Component
{

private:
    Vector3 m_position;
    Quaternion m_rotation;
    Vector3 m_scale = {1.0f, 1.0f, 1.0f};

    Matrix4 m_modelMatrix = Matrix4();

    bool m_isDirty = false;

    Matrix4 getLocalModelMatrix();

public:
    Transform(std::shared_ptr<GameObject> parent) : Component(parent) {}

    void computeModelMatrix();

    void computeModelMatrix(const Matrix4 &parentMatrix);

    void setLocalPosition(const Vector3 &position);

    void setLocalRotation(const Vector3 &rotation);

    void setLocalScale(const Vector3 &scale);

    Vector3 &getLocalPosition();

    Quaternion &getLocalRotation();

    Vector3 &getLocalScale();

    Matrix4 &getModelMatrix();

    bool isDirty() const;
};

#endif
