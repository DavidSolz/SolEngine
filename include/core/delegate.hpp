#ifndef DELEGATE_H
#define DELEGATE_H

#include <vector>
#include <memory>
#include <functional>

template <typename ReturnType, typename... Args>
class Delegate
{
public:
    using FunctionType = std::function<ReturnType(Args...)>;

private:
    std::vector<FunctionType> m_functions;

public:
    void add(FunctionType func)
    {
        m_functions.push_back(func);
    }

    void remove(FunctionType func)
    {
        m_functions.erase(
            std::remove_if(m_functions.begin(), m_functions.end(),
                           [&](const FunctionType &f)
                           {
                               return f.target_type() == func.target_type();
                           }),
            m_functions.end());
    }

    Delegate &operator+=(FunctionType func)
    {
        add(func);
        return *this;
    }

    Delegate &operator-=(FunctionType func)
    {
        remove(func);
        return *this;
    }

    void invoke(Args... args) const
    {
        for (const auto &func : m_functions)
            func(args...);
    }
};

#endif
