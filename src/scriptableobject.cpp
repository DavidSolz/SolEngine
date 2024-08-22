#include "scriptableobject.h"

void ScriptableObject::serialize(const std::string &filename) const
{
    std::ofstream outFile(filename, std::ios::binary);

    if (outFile.is_open() == false)
        return;

    std::string typeName = getTypeName();

    size_t len = typeName.size();

    outFile.write(reinterpret_cast<const char *>(&len), sizeof(len));
    outFile.write(typeName.data(), len);

    serialize(outFile);

    outFile.close();
}

std::shared_ptr<ScriptableObject> ScriptableObject::deserialize(const std::string filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open() == false)
        return nullptr;

    size_t len = 0;
    inFile.read(reinterpret_cast<char *>(&len), sizeof(len));

    std::string typeName(len, '\0');
    inFile.read(&typeName[0], len);

    auto it = registry().find(typeName);
    if (it != registry().end())
    {
        std::unique_ptr<ScriptableObject> obj = it->second();
        obj->deserialize(inFile);
        return obj;
    }

    return nullptr;
}

std::unordered_map<std::string, ScriptableObject::CreatorFunc> &ScriptableObject::registry()
{
    static std::unordered_map<std::string, CreatorFunc> registry;
    return registry;
}
