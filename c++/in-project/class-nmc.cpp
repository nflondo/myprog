#include <cstdio>

class Myclass {
//members default to private in a class while they default to public
// in a struct
    int i = 0; // this is private

public: //declares a public section
    void setvalue( int value ) { i = value; }
    int getvalue() {return i;}
};

int main(){
    int i = 47;
    Myclass o1;

    o1.setvalue(i); // dot notation
    printf("value is %d\n", o1.getvalue());
    return 0;
}