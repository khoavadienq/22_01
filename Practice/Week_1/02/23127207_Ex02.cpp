#include "subFunction.h"

int main(){
    int num_line = countLine();
    Student stu[num_line];

    readFile(num_line, stu);
    int nSz;
    Student stu_best_gpa[num_line];

    filtBestGPA(num_line, stu, nSz, stu_best_gpa); 
    printFile(nSz, stu_best_gpa);
    return 0;
}
