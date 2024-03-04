#include "Ex1.h"

int main(){
    Node *head = NULL;

    readFile(head);
    removeAllX(head);
    printList(head);
    deleteList(head);
    return 0;
}