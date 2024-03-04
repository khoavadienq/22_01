#include "Ex4.h"

int main(){
    int *arr;
    int size;
    cout << "Input size: ";
    cin >> size;

    arr = new int[size];
    for (int i = 0; i < size; i++){
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Mode: ";
    printMode(arr, size);
    
    delete[] arr;
    return 0;
}

