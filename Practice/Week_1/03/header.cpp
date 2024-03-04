#include "header.h"

int calPower(int n, int T1, int T2, int P1, int P2, int P3, int lt[], int rt[]){
    int time, sum = 0;
    for (int i = 0; i < n; i++) {
        time = (i == n - 1) ? 0 : lt[i + 1] - rt[i];
        time = max(0, time);

        sum += P1 * (rt[i] - lt[i]);

        if (time <= T1) 
            sum += time * P1;
        else {
            sum += T1 * P1;

            if (time - T1 <= T2)
                sum += (time - T1) * P2;
            else {
                sum += T2 * P2;
                sum += (time - T2 - T1) * P3;
            }
        }
    }
    return sum;
}
