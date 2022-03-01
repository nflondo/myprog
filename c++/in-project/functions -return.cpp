#include <cstdio>
#include <string>

const std::string & func(){
    const static std::string s = "this is from func()";
    return s;    
}

int main(){
    puts("this is main()");
    const std::string s = func();
    printf("s is %s\n", s.c_str());
    return 0;
}