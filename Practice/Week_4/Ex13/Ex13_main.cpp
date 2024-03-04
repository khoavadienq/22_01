#include "Ex13.h"

int main(){
    int x;
    Node *head = nullptr;
    readFile(head, x);
    
    printList(head, x);
    deleteList(head);
    return 0;
}