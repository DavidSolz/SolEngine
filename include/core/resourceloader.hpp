#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include <map>
#include <list>
#include <memory>
#include <mutex>

template <typename T>
class ResourceLoader
{
private:
    std::map<std::string, std::pair<unsigned int, std::shared_ptr<T>>> m_resources;
    std::list<unsigned int> m_unusedID;

    unsigned int m_resourceID;
    std::mutex m_mutex;

public:
    unsigned int add(const std::string &filepath)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        auto it = m_resources.find(filepath);

        if (it != m_resources.end())
        {
            return it->second.first;
        }

        std::shared_ptr<T> resource = std::make_shared<T>();
        if (!resource->loadFromFile(filepath))
        {
            return -1;
        }

        unsigned int id = 0;

        if (m_unusedID.empty() == true)
        {
            id = m_resourceID++;
        }
        else
        {
            id = m_unusedID.front();
            m_unusedID.pop_front();
        }

        m_resources.insert(std::make_pair(filepath, std::make_pair(id, resource)));

        return id;
    }

    void remove(const unsigned int &id)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        for (auto it = m_resources.begin(); it != m_resources.end(); ++it)
        {
            if (it->second.first == id)
            {
                m_resources.erase(it->first);
                m_unusedID.push_back(id);
            }
        }
    }

    std::shared_ptr<T> getResource(const unsigned int &id)
    {
        for (auto it = m_resources.begin(); it != m_resources.end(); ++it)
        {
            if (it->second.first == id)
            {
                return it->second.second;
            }
        }
        return nullptr;
    }
};

#endif
