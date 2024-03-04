#include "Ex9.h"

/*
    Test case 1: 
        Input: n = 3
            food[1][] = {1, 2, 3, 4, 5, 6, 7};
            food[2][] = {4, 5, 6, 7, 8, 9, 10};
            food[3][] = {2, 3, 4, 5, 6, 7, 8};
        Ouput: 
            Average food on day 1: 2.33333
            Average food on day 2: 3.33333
            Average food on day 3: 4.33333
            Average food on day 4: 5.33333
            Average food on day 5: 6.33333
            Average food on day 6: 7.33333
            Average food on day 7: 8.33333
            The least amount of pound of food: 28
            The max amount of pound of food: 49
    Test case 2: 
        Input: n = 2
            food[1][] = {0, 2, 3.2, 4.1, 5.2, 5.3, 4.5}
            food[2][] = {2.4, 2.1, 34, 2.3, 1.2, 0.2, 0.23}
        Output: 
            Average food on day 1: 1.2
            Average food on day 2: 2.05
            Average food on day 3: 18.6
            Average food on day 4: 3.2
            Average food on day 5: 3.2
            Average food on day 6: 2.75
            Average food on day 7: 2.365
            The least amount of pound of food: 24.3
            The max amount of pound of food: 42.43
    Test case 3: 
        Input: n = 0
        Output: Error
    
    Test case 4: 
        Input: n = 2
            food[1][] ={0, -2,...}
        Output: 
            Pound cannot be negative.
*/

void input(double **&food, int n, bool &check){
    for (int i = 0; i < n; i++){
        cout << "Enter pound of food for monkey " << i + 1 << ": \n";
        for (int j = 0; j < 7; j++){
            cout << "   Enter pound of food on day " << j + 1 << ": ";
            cin >> food[i][j];
            if (food[i][j] < 0) {
                cout << "Pound cannot be negative.";
                check = false;
                return;
            }
        }
    }
}

double averageFoodOneDay(double **food, int n, int day){
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += food[i][day];
    return sum / n;
}

double sumPoundFoodOneMonkey(double *food, int num_days){
    double sum = 0;
    for(int i = 0; i < num_days; i++)
        sum += food[i];
    return sum;    
}

double findMinPound(double **food, int n){
    double min = sumPoundFoodOneMonkey(food[0], 7);

    for (int i = 1; i < n; i++){
        double sum = sumPoundFoodOneMonkey(food[i], 7);
        if (sum < min)
            min = sum;
    }

    return min;
}

double findMaxPound(double **food, int n){
    double max = sumPoundFoodOneMonkey(food[0], 7);

    for (int i = 1; i < n; i++){
        double sum = sumPoundFoodOneMonkey(food[i], 7);
        if (sum > max)
            max = sum;
    }

    return max;
}
