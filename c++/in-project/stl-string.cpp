// passing a reference. good idea for large objects
#include <cstdio>
#include <string>

void func(const std::string & s){ //const is recommended for reference &
    printf("the value is: %s\n", s.c_str());
}

int main(){
    std::string s = "This is a string"; //string object
    puts("This is Main()");
    func(s);
    return 0;
}