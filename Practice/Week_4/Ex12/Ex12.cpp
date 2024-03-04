#include "Ex12.h"

Node *makeNode(int x){
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void readFile(Node*& head1, Node*& head2, int &x) {
    ifstream input("input.txt");
    if (!input.is_open()) {
        cout << "Can not open input.txt";
        return;
    }

    int n;
    input >> n;
    Node* newNode = makeNode(n);

    if (n != 0) {
        head1 = newNode;
    } else {
        input.close();
        return;
    }

    Node* tmp = head1;
    while (input >> n) {
        if (n == 0)
            break;
        else {
            newNode = makeNode(n);
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
    tmp->next = nullptr;

    input >> n;
    newNode = makeNode(n);
    if (n != 0) {
        head2 = newNode;
    } else {
        input.close();
        return;
    }

    tmp = head2;
    while (input >> n) {
        if (n == 0)
            break;
        else {
            newNode = makeNode(n);
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
    tmp->next = nullptr;

    input.ignore(1, '\n');
    input >> x;

    input.close();
}

int countList(Node *head){
    int count = 0;
    while(head != nullptr){
        count ++;
        head = head->next;
    }

    return count;
}

void linkList(Node *head1, Node *&head2, int x){
    for(int i = 1; i <= x - 1; i++){
        head1 = head1->next;
    }

    Node *tmp = head2;
    while (tmp->next != nullptr) tmp = tmp->next;
    tmp->next = head1;
}

void printList(Node *head, int x){
    ofstream output("output.txt");
    if (!output.is_open()){
        cout << "Cannot open this file";
        return;
    }

    for(int i = 1; i < x; i++){
        head = head->next;
    }

    output << head->data;

    output.close();
}

void deleteList(Node *&head){
    Node *cur = head, *tmp = NULL;
    if (head == NULL) return;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}