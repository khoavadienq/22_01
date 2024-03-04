#include "Ex03.h"
/*
    Test case 1: 
        12321 
        true
    Test case 2:
        aad 
        false
    Test case 3:
        adad
        false
    Test case 4:
        s 
        true 

*/

bool isPalindrome(char* cstr)
{
    char* front = cstr;
    char* back = cstr + strlen(cstr)-1;
    while (front < back)
    {
        if (*front != *back) return false;
        front++;
        back--;
    }
return true;
}