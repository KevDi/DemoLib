#pragma once
#include <string>

#include "export.hpp"

class MYLIB_EXPORT MyLib {
   public:
    virtual std::string name() const = 0;
    virtual ~MyLib();
};