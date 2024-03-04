#include "Ex03.h"

int main(){
    char *cstr;
    cstr = new char[100];

    cout << "Input: ";
    cin.getline(cstr, 100);
    
    if (isPalindrome(cstr)) 
        cout << "Is Palindrome";
    else cout << "Not Palndrome";

    delete[] cstr;
    return 0;
}
