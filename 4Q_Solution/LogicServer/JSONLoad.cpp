#include "JSONLoad.h"

json JSONLoad::DeSerialize(const std::string& fileName)
{
    // JSON ������ �о����
    std::ifstream file(fileName);
    file >> _mapData;

    // ������ȭ
    return _mapData;
}
