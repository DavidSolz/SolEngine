#include "scene.h"

std::shared_ptr<GameObject> Scene::createObject()
{
    auto allocatorPtr = std::make_shared<ComponentAllocator>(m_allocator);
    std::shared_ptr<GameObject> object = std::make_shared<GameObject>(m_objectID, allocatorPtr);
    m_objectID++;
    m_objects.add(object);
    return object;
}
