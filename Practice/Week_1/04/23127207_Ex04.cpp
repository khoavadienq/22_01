#include "header.h"

int main(){
    int n, d;
    cin >> n >> d;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i]; 

    cout << calMove(a, n, d);
}