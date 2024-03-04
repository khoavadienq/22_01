#include "Ex5.h"

int main(){
    int x; Node* head = NULL;
    readFile(head, x);
    insertIntoSortedList(head, x);
    printList(head);
    deleteList(head);
    return 0;
}
