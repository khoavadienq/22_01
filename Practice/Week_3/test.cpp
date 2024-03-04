#include <iostream>

using namespace std;

int* findMaxFrequency(int* a, int n, int &tmp);

int main(){
    int n = 5, tmp = 0;
    int* arr = new int[n] {1, 1, 2, 2, 3};
    int* a = findMaxFrequency(arr, n, tmp);
    cout << "Số xuất hiện nhiều nhất trong mảng là: ";

    for (int i = 0; i < tmp; i++)
        cout << a[i] << " ";
    delete[] arr;
    return 0;
}

int* findMaxFrequency(int* a, int n, int &tmp){
    int max = 1, cnt = 1;
    int* num = new int[n];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(*(a + j) == *(a + i))
                cnt++;
        }
        if(cnt > max){
            max = cnt;
        }
        cnt = 1;
    }

    if (max == 1) {
        num[tmp] = -1;
        return num;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(*(a + j) == *(a + i))
                cnt++;
        }
        if(cnt == max){
            num[tmp++] = *(a + i);
        }
        cnt = 1;
    }
    
    if(max == 1) {
        tmp = 0;
        num[tmp++] = -1;
    }
    return num;
}
