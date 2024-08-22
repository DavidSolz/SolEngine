#ifndef SCRIPTABLE_OBJECT_H
#define SCRIPTABLE_OBJECT_H

#include <functional>
#include <string>
#include <fstream>
#include <unordered_map>

class ScriptableObject
{
private:
    using CreatorFunc = std::unique_ptr<ScriptableObject> (*)();
    static std::unordered_map<std::string, CreatorFunc> &registry();

protected:
    virtual void
    serialize(std::ofstream &output) const = 0;

    virtual void deserialize(std::ifstream &input) = 0;

public:
    virtual void serialize(const std::string &filename) const;

    static std::shared_ptr<ScriptableObject> deserialize(const std::string filename);

    virtual std::string getTypeName() const = 0;

    virtual ~ScriptableObject() = default;
};

#endif
