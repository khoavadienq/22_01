#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
Format files:
No|Student ID|First name|Last name| Gender| Date of birth|Social ID

*/
struct Stu{
    int No, ID;
    string first_name, last_name, gender, date, socialID;

    void input();
};

// struct Class{
//     Stu *student;
//     Class *next;

//     void input(){
//         student.input();
//     }
//     Class(){
//         next = nullptr;
//     }
// };

struct Course{
    string course_id, course_name, class_name, teacher_name;
    unsigned int number_credits;
    const int max_stu = 50;
    string day, time;
};

struct Semester{
    unsigned int num_semester, school_year;
    string start, end;
    Course courses;
    Semester *next;
};

struct Year{
    Semester semesters;
    Year *next;
};

void readFile(Stu *students);

// void printListToScreen( );

// void printListToFiles( );

int main(){



    return 0;
}