#include "Ex6.h"

int main(){
    int *arr, size;
    cout << "Input size: ";
    cin >> size;
    
    arr = new int[size];
    inputArray(arr, size);

    int *double_arr = doubleArray(arr, size);
    printArray(double_arr, size);
    delete[] arr;
    delete[] double_arr;
    return 0;
}

