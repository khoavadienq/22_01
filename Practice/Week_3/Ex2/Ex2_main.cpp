#include<iostream>
#include "Ex2.h"

int main(){
    int *a, *b;
    a = new int;
    b = new int;
    cin >> *a >> *b;
    cout << doSomthing(a, b);
    delete a;
    delete b;
    return 0;
}
