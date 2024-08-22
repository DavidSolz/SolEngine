#ifndef SPARSE_SET_H
#define SPARSE_SET_H

#include <vector>
#include <stdint.h>
#include <memory>
#include <unordered_map>

template <typename K, typename V>
class SparseSet
{
private:
    std::vector<V> m_values;
    std::vector<K> m_keys;
    std::unordered_map<K, uint32_t> m_sparse;

public:
    void reserve(const size_t &capacity)
    {
        m_values.reserve(capacity);
        m_keys.reserve(capacity);
        m_sparse.reserve(capacity);
    }

    void insert(const K &key, const V &value)
    {

        auto it = m_sparse.find(key);

        if (it != m_sparse.end())
        {
            uint32_t index = it->second;

            m_values[index] = value;
            return;
        }

        m_sparse[key] = m_values.size();
        m_values.emplace_back(value);
        m_keys.emplace_back(key);
    }

    void remove(const K &key)
    {
        auto it = m_sparse.find(key);
        if (it == m_sparse.end())
            return;

        size_t index = it->second;
        K lastKey = m_keys.back();

        std::swap(m_values[index], m_values.back());
        std::swap(m_keys[index], m_keys.back());

        m_sparse[lastKey] = index;

        m_values.pop_back();
        m_keys.pop_back();
        m_sparse.erase(it);
    }

    std::shared_ptr<V> get(const K &key) const
    {
        auto it = m_sparse.find(key);

        if (it != m_sparse.end())
            return std::make_shared<V>(m_values[it->second]);

        return nullptr;
    }

    bool has(const K &key) const
    {
        return m_sparse.find(key) != m_sparse.end();
    }

    void clear()
    {
        m_values.clear();
        m_keys.clear();
        m_sparse.clear();
    }

    size_t size() const
    {
        return m_values.size();
    }

    bool empty() const
    {
        return m_values.empty();
    }

    const std::vector<K> &keys() const
    {
        return m_keys;
    }

    const std::vector<V> &values() const
    {
        return m_values;
    }
};

#endif
