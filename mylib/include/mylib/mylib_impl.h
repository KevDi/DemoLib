#pragma once
#include "export.hpp"
#include "mylib.h"

class MYLIB_EXPORT MyLibImpl : public MyLib {
   public:
    virtual std::string name() const override;
    virtual ~MyLibImpl();
};