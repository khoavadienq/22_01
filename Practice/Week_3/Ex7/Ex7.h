#pragma once
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void readFile(const char* name_file, char* answers);
bool compareAnswers(char stu, char correct);
void findWrongAnswers(char* correct, char* stu, int& wrong_answers);
bool checkPercent(int wrong_answers);