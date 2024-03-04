#include "Ex3.h"

int main(){
    Node *head = NULL;

    readFile(head);
    reserveList(head);
    printList(head);

    deleteList(head);
    return 0;
}