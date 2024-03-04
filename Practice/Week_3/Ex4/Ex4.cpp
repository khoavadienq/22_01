#include "Ex4.h"

void sortArr(int *&arr, int size){
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

/*
    Test case 1: 
        arr[] = {1, 1, 2, 2, 3, 3,3}
        3
    Test case 2:
        arr[] = {};
        -1 
    Test case 3:
        arr[] = {1, 2, 3, 4};
        -1
    Test case 4:
        arr[1, 1, 2, 2, 3, 3];
        1 2 3
*/

void printMode(int *arr, int size){
    if (size <= 0) {
        cout << "-1";
        return ;
    }
    sortArr(arr, size);

    int cur_count = 1, cur_value = arr[0], max_count = 0, max_value = arr[0];

    for (int i = 0; i < size - 1; i++){
        if (arr[i] == arr[i + 1])
            cur_count ++;
        else {
            cur_count = 1;
            cur_value = arr[i + 1];
        }

        if (cur_count > max_count){
            max_count = cur_count;
            max_value = cur_value;
        }
    }
    
    if (max_count == 1) {
        cout << "-1";
        return;
    }

    cur_count = 1;
    for (int i = 0; i < size - 1; i++){
        if (arr[i] == arr[i + 1]){
            cur_count++;
        } else {
            if (cur_count == max_count )
                cout << arr[i] << " ";
            cur_count = 1;
        }
    }
    
    if (cur_count == max_count)
        cout << arr[size - 1];
    
}
