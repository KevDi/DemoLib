#include <consumer/consumer.h>
#include <mylib/mylib_impl.h>

#include <iostream>

int main() {
    std::cout << "Hello World!\n";
    std::unique_ptr<MyLib> mylib = std::make_unique<MyLibImpl>();
    Consumer consumer{std::move(mylib)};
    std::cout << consumer.data() << '\n';
    return 0;
}