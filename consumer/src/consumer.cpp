#include "consumer/consumer.h"

#include <mylib/mylib_impl.h>

#include <iostream>
#include <sstream>

Consumer::Consumer(std::unique_ptr<MyLib> mylib) : myLib_{std::move(mylib)} {
}

std::string Consumer::data() const {
    MyLibImpl impl;
    std::cout << impl.name() << '\n';
    std::stringstream ss;
    ss << "MyLib Name: ";
    ss << myLib_->name();
    return ss.str();
}