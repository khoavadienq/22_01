#include "Ex5.h"

int main(){
    int *arr, size;
    cout << "Size = ";
    cin >> size;
    if (size == 0) cout << "No elements";
     else {
        arr = new int[size];
        input(arr, size);
        cout << "Median = " << calMedian(arr, size);
        delete[] arr;
     }
    return 0;
}