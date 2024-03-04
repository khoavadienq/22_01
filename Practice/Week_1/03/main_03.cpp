#include "header.h"

int main(){
    int n;
    int T1, T2, P1, P2, P3;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;

    int lt[n], rt[n];
    for (int i = 0; i < n; i++)
        cin >> lt[i] >> rt[i];

    cout << calPower(n, T1, T2, P1, P2, P3, lt, rt);
    return 0;
}
