#pragma once
#include <string>

class IObserver
{
public:
    IObserver() = default;
    virtual void Update(const std::string &key, const std::string &data) = 0;
};
