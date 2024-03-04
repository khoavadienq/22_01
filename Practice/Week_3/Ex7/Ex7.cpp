#include "Ex7.h"

void readFile(const char* name_file, char* answers) {
    ifstream input(name_file);
    if (!input.is_open()) {
        cout << "Cannot open " << name_file;
        return;
    }

    for (int i = 0; i < 20; i++){
        input.getline((answers + i), 100);
        input.ignore('\n');
    }

    input.close();
}


bool compareAnswers(char stu, char correct) {
    return stu != correct;
}

void findWrongAnswers(char* correct, char* stu, int& wrong_answers) {
    for (int i = 0; i < 20; i++) {
        if (compareAnswers(*stu, *correct)) {
            wrong_answers++;
            cout << "Answer " << i + 1 << " is wrong\n";
        }
        correct ++;
        stu ++;
    }
    cout << "-------------------\n";
    cout << "Number of wrong answers: " << wrong_answers << endl;
}

bool checkPercent(int wrong_answers) {
    return (wrong_answers <= 6); 
}
