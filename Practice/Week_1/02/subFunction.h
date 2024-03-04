#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student{
    char ID[100];
    char fullname[100];
    double GPA;
};

int countLine();
void readFile(int n, Student stu[]);
void filtBestGPA(int n, Student stu[], int &nSz, Student stu_best_gpa[]);
double findMax(int n, Student stu[]);
void printFile(int n, Student stu[]);