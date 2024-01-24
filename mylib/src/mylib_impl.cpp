#include "mylib/mylib_impl.h"

#include "privlib.h"

std::string MyLibImpl::name() const {
    PrivLib privLib;
    return privLib.name();
}

MyLibImpl::~MyLibImpl() = default;