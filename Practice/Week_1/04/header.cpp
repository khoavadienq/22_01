#include "header.h"

int calMove(int a[], int n, int d){
    int moves = 0, tmp, buffer;
    for (int i = 1; i < n; i++)
        if (a[i - 1] >= a[i]){
            tmp = a[i - 1] - a[i];
            buffer = tmp / d + 1;
            moves += buffer;
            a[i] += d * buffer;
        }
    return moves;
}