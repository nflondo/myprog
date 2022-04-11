// exception.cpp by Bill Weinman <http://bw.org/>
// updated 2002-09-03
#include <iostream>
#include <exception>

namespace BW {
    class E : public std::exception {
        const char * msg;
        E();
    public:
        E(const char *s) noexcept(true) : msg(s) {}
        const char * what() const noexcept(true) { return msg; }
    };
}
//Define your exceptions
const BW::E e_ouch("ouch!");
const BW::E e_bad("bad code!");
const BW::E e_worse("don't do that!");

void broken() {
    std::cout << "this is a broken function" << std::endl;
    //throw std::exception();
    throw e_worse;
}

int main() {
    std::cout << "let's have an emergency!" << std::endl;
    try {
        broken();
    } catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
