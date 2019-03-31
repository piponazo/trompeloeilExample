#pragma once

#include <string>

class Store
{
public:
    virtual size_t inventory(const std::string& name) const = 0;
    virtual void remove(const std::string& name, size_t amount) = 0;
};
