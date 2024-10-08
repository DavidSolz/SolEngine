#include "transform.h"

Matrix4 Transform::getLocalModelMatrix()
{
    Matrix4 translation = Matrix4::translate(m_position);
    Matrix4 rotation = Matrix4::rotate(m_rotation.w, Vector3(m_rotation.x, m_rotation.y, m_rotation.z));
    Matrix4 scale = Matrix4::scale(m_scale);

    return translation * rotation * scale;
}

void Transform::computeModelMatrix()
{
    this->m_modelMatrix = getLocalModelMatrix();
    this->m_isDirty = false;
}

void Transform::computeModelMatrix(const Matrix4 &parentMatrix)
{
    this->m_modelMatrix = parentMatrix * getLocalModelMatrix();
    this->m_isDirty = false;
}

void Transform::setLocalPosition(const Vector3 &position)
{
    this->m_position = position;
    this->m_isDirty = true;
}

void Transform::setLocalRotation(const Vector3 &rotation)
{
    this->m_rotation = Quaternion::ToQuaternion(rotation);
    this->m_isDirty = true;
}

void Transform::setLocalScale(const Vector3 &scale)
{
    this->m_scale = scale;
    this->m_isDirty = true;
}

void Transform::update([[maybe_unused]] const float &deltaTime)
{

    if (m_isDirty == false)
        return;

    computeModelMatrix();
}

void Transform::setX(const float &x)
{
    m_position.x = x;
    m_isDirty = true;
}

void Transform::setY(const float &y)
{
    m_position.y = y;
    m_isDirty = true;
}

void Transform::setZ(const float &z)
{
    m_position.z = z;
    m_isDirty = true;
}

float Transform::getX() const
{
    return m_position.x;
}

float Transform::getY() const
{
    return m_position.y;
}

float Transform::getZ() const
{
    return m_position.z;
}

Vector3 &Transform::getLocalPosition()
{
    return m_position;
}

Quaternion &Transform::getLocalRotation()
{
    return m_rotation;
}

Vector3 &Transform::getLocalScale()
{
    return m_scale;
}

Matrix4 &Transform::getModelMatrix()
{
    return m_modelMatrix;
}

bool Transform::isDirty() const
{
    return m_isDirty;
}
