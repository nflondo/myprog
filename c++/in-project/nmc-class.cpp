// class.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

// a very simple class.  This is the interface part, usually in a separate file.
class C1 {
    int i = 0;
public:
    void setvalue( int value );
    int getvalue(); 
};
// this is the implementation part
void C1::setvalue( int value){ //:: tells the compiler this is the definition
    i = value; 
}

int C1::getvalue() { 
    return i; 
}

int main() {
    int i = 47;
    C1 o1;
    
    o1.setvalue(i);
    printf("value is %d\n", o1.getvalue());
    return 0;
}