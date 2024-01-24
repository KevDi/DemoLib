#pragma once
#include <mylib/mylib.h>

#include <memory>
#include <string>

#include "export.hpp"

class CONSUMER_EXPORT Consumer {
   public:
    Consumer(std::unique_ptr<MyLib> mylib);
    std::string data() const;

   private:
    std::unique_ptr<MyLib> myLib_;
};