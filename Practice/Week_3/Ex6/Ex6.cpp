#include "Ex6.h"

/*
    Test case 1: 
        arr[] = {1, 2, 3, 4, 5}
        1 2 3 4 5 0 0 0 0 0
    Test case 2:
        arr[] = { }
        No size
    Test case 3: 
        arr[] = {2}
        2 0
*/
void inputArray(int *&arr, int size){
    if (size <= 0) {
        cout << "No size";
        return;
    }
    for (int i = 0; i < size; i++){
        cout << "arr[" << i << "] ";
        cin >> arr[i];
    }
}



int *doubleArray(int *arr, int size){
    int *double_arr;
    double_arr = new int[size * 2];
    for(int i = 0; i < size * 2; i++)
        if (i < size)
            double_arr[i] = arr[i];
        else double_arr[i] = 0;
    return double_arr;
}

void printArray(int *double_arr, int size){
    if (size == 0) return;
    for (int i = 0; i < size * 2; i++)
        cout << double_arr[i] << " ";
}