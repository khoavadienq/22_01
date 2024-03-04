#include "Ex4.h"

int main(){
    Node *head = NULL;
    readFile(head);
    insertEvenNumbers(head);
    printList(head);
    deleteList(head);
    return 0;
}
