#include "Ex9.h"

int main(){
    int n;
    cout << "Numbers of monkeys: ";
    cin >> n;
    if (n <= 0) {
        cout << "Error";
        return -1;
    }

    double **food;
    bool check = true;
    food = new double*[n];
    for (int i = 0; i < n; i++)
        food[i] = new double[7];

    input(food, n, check);
    if (!check) {
        return -1;
    }

    for (int i = 0; i < 7; i++){
        cout << "Average food on day " << i + 1 << ": " << averageFoodOneDay(food, n, i) << endl;                
    }

    cout << "The least amount of pound of food: " << findMinPound(food, n) << endl;
    cout << "The max amount of pound of food: " << findMaxPound(food, n) << endl;

    for (int i = 0; i < n; i++)
        delete[] food[i];
    delete[] food;

    return 0;
}