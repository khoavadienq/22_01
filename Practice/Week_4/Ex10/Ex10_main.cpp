#include "Ex10.h"

int main(){
    Node *head = nullptr;
    readFile(head);
    print(changeListIntoNum(head));
    deleteList(head);
    return 0;
}