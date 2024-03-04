#include "subFunction.h"

int countLine(){
    ifstream  input;
    input.open("input.txt");

    if (!input.is_open())
        return -1;
    
    int count_line = 0;
    char line;

    while (input.get(line))
        if (line == '\n') 
            count_line ++;
    
    if (input.eof())
        count_line ++;
    
    input.close();
    return count_line;
}

void readFile(int n, Student stu[]){
    ifstream input;
    input.open("input.txt");

    if (!input.is_open()) {
        cout << "Cannot open input.txt";
        return;
    }

    for (int i = 0; i < n; i++){
        input.getline(stu[i].ID, 100, ' ');
        input.getline(stu[i].fullname, 100, ' ');
        input >> stu[i].GPA;
        input.ignore(100, '\n');
    }

    input.close();
}

void printFile(int n, Student stu[]){
    ofstream output;
    output.open("ouput.txt");

    output << "Top best GPA students: \n";
    for(int i = 0; i < n; i++)
        output << stu[i].ID << " " << stu[i].fullname << " " << stu[i].GPA << endl;
    cout << "Done!";

    output.close();
}

double findMax(int n, Student stu[]){
    double max = stu[0].GPA;
    for (int i = 1; i < n; i++) 
        if (stu[i].GPA > max) max = stu[i].GPA;
    return max;
}

void filtBestGPA(int n, Student stu[], int &nSz, Student stu_best_gpa[]){
    double max = findMax (n, stu);
    nSz = 0;

    for (int i = 0; i < n; i++) 
        if (stu[i].GPA == max)
            stu_best_gpa[nSz++] = stu[i];
    
}