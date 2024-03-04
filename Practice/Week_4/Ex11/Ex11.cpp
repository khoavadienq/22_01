#include "Ex11.h"

Node *makeNode(int x){
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void readFile(int &x){
    ifstream input("input.txt");
    if (!input.is_open()){
        cout << "Cannot open input.txt";
        return;
    }

    input >> x;
    x /= 10;
    input.close();
}

Node *turnNumIntoList(int x){
    Node *newList = nullptr, *newNode = nullptr;
    while(x != 0){
        newNode = makeNode(x % 10);

        newNode->next = newList;
        newList = newNode;
        x /= 10;
    }

    return newList;
}

void printList(Node *head){
    ofstream output("output.txt");
    if (!output.is_open()){
        cout << "Cannot open this file";
        return;
    }

    if(head == NULL){
        output << "No data";
        return;
    }

    while(head != NULL) {
        output << head->data << " ";
        head = head->next;
    }

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