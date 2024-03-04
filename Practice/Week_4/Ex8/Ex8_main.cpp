#include "Ex8.h"

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    readFile(head1, head2);
    Node* newList = combineTwoLists(head1, head2);
    printList(newList);
    deleteList(newList);
    return 0;
}