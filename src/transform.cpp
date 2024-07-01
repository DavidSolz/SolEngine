#include "transform.h"

Matrix4 Transform::getLocalModelMatrix(){

    Matrix4 translation = Matrix4::translate(m_position);
    // TODO
    Matrix4 rotation = Matrix4();
    Matrix4 scale = Matrix4::scale(m_scale);

    return translation * rotation * scale;

}

void Transform::computeModelMatrix(){
    this->m_modelMatrix = getLocalModelMatrix();
    this->m_isDirty = false;
}

void Transform::computeModelMatrix(const Matrix4 & parentMatrix){
    this->m_modelMatrix = parentMatrix * getLocalModelMatrix();
    this->m_isDirty = false;
}

void Transform::setLocalPosition(const Vector3 & position){
    this->m_position = position;
    this->m_isDirty = true;
}

void Transform::setLocalRotation(const Vector3 & rotation){
    this->m_rotation = rotation;
    this->m_isDirty = true;
}

void Transform::setLocalScale(const Vector3 & scale){
    this->m_scale = scale;
    this->m_isDirty = true;
}

Vector3& Transform::getLocalPosition(){
    return m_position;
}

Vector3& Transform::getLocalRotation(){
    return m_rotation;
}

Vector3& Transform::getLocalScale(){
    return m_scale;
}

Matrix4& Transform::getModelMatrix(){
    return m_modelMatrix;
}

bool Transform::isDirty() const{
    return m_isDirty;
}
