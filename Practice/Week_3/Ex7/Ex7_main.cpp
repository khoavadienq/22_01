#include "Ex7.h"

int main() {
    const char* correctAnswersFile = "CorrectAnswers.txt";
    const char* studentAnswersFile = "StudentAnswers.txt";
    
    char *studentAnswers, *correctAnswers;
    studentAnswers = new char[20];
    correctAnswers = new char[20];
    
    readFile(correctAnswersFile, correctAnswers);
    readFile(studentAnswersFile, studentAnswers);

    int wrong_answers = 0;
    findWrongAnswers(correctAnswers, studentAnswers, wrong_answers);
    if (checkPercent(wrong_answers)) 
        cout << "You pass the exam";
    else 
        cout << "You fail the exam";

    delete[] studentAnswers;
    delete[] correctAnswers;
    return 0;
}
