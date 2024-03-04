#include "Ex9.h"

int main(){
    Node *head1 = nullptr, *head2 = nullptr;
    readFile(head1, head2);
    Node *newList = combineTwoLists(head1, head2);
    printList(newList);
    deleteList(newList);
    return 0;
}