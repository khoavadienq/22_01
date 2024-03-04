#include "Ex12.h"

int main(){
    Node *head1 = nullptr, *head2 = nullptr;
    int x;
    readFile(head1, head2 , x);
    if (countList(head1) > countList(head2)) {
        linkList(head1, head2, x);
        printList(head1, x);
    }
        else if(countList(head1) <= countList(head2)) {
            linkList(head2, head1, x);
            printList(head2, x);
        }
            else cout << "Same length";
    
    return 0;
}