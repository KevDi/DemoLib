#include "consumer/consumer.h"

#include <iostream>
#include <sstream>

Consumer::Consumer(std::unique_ptr<MyLib> mylib) : myLib_{std::move(mylib)} {
}

std::string Consumer::data() const {
    std::stringstream ss;
    ss << "MyLib Name: ";
    ss << myLib_->name();
    return ss.str();
}