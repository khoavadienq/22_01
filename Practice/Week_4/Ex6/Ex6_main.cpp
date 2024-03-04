#include "Ex6.h"

int main(){
    Node *head = NULL;
    readFile(head);
    Node *newList = sumElementsOfList(head);
    printList(newList);
    deleteList(head);
    return 0;
}