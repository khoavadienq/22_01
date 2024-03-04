#pragma once 
#include <iostream>

using namespace std;

void input(double **&food, int n, bool &check);
double averageFoodOneDay(double **food, int n, int day);
double sumPoundFoodOneMonkey(double *food, int num_days);
double findMinPound(double **food, int n);
double findMaxPound(double **food, int n);