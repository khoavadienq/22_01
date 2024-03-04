#include <iostream>
#include <fstream>

using namespace std;

bool checkFile(){
    ifstream output("output.txt");
    if (!output.is_open()){
        cout << "Cannot open file";
        return false;
    }

    output.seekg(0, std::ios::end);
    if (output.tellg() == 0) return false;
        else return true;
}

int main(){
    if(checkFile()) cout << "1";
        else cout << "0";
    return 0;
}