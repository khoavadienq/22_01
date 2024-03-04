#include "Ex5.h"

/*
    Test case 1: 
        arr[] = {1, 2, 3}
        2
    Test case 2: 
        arr[] = {5 6 3 7 20 43}
        5
    Test case 3:
        arr[] = {3, 53, 12, 5}
        32.5
    Test case 4:
        arr[] = { }
        No elements
    Test case 5:
        arr[] = {1, 2}
        1.5

*/
void input(int *&arr, int size){
    if (size == 0) return;
    for (int i = 0; i < size; i++)
        cin >> *(arr + i);
}

double calMedian(int *arr, int size){
    if (size % 2 != 0){
        return arr[size / 2 ];
    } else {
        double tmp = (static_cast<double>(arr[size / 2]) + static_cast<double>(arr[size / 2 - 1])) / 2;

        return tmp;
    }
}