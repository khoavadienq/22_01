#include "Ex11.h"

int main(){
    int x;
    readFile(x);
    Node *head = turnNumIntoList(x);
    printList(head);
    deleteList(head);
    return 0;
}