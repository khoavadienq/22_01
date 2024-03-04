#include "Ex2.h"

/*
    Test Case 1: 
        x = 5, y = 6
        110
    Test Case 2:
        x = -6, y = 0
        -60

*/
int doSomthing(int *&x, int *&y){
    int *tmp;
    tmp = new int;
    *tmp = *x;
    *x = *y * 10;
    *y = *tmp * 10;
    delete tmp;
    return *x + *y;
}