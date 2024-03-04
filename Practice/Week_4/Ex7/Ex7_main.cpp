#include "Ex7.h"

int main(){
    Node *head = NULL;
    readFile(head);
    Node *newList = splitIntoTwoList(head);
    printList(newList);
    printList(head);
    deleteList(head);
    return 0;
}