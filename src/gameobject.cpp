#include "gameobject.hpp"

GameObject::GameObject(const unsigned int &id, std::shared_ptr<ComponentAllocator> allocator)
{
    this->m_id = id;
    this->m_allocator = allocator;
    this->transform = addComponent<Transform>();
}

void GameObject::awake()
{
    m_allocator->awake(m_id);
}

void GameObject::start()
{
    m_allocator->start(m_id);
}

void GameObject::update(const float &deltaTime)
{
    m_allocator->update(m_id, deltaTime);
}

void GameObject::fixedUpdate(const float &deltaTime)
{
    m_allocator->fixedUpdate(m_id, deltaTime);
}

void GameObject::draw(GLShader &shader)
{
    m_allocator->draw(m_id, shader);
}

unsigned int GameObject::getID() const
{
    return m_id;
}
