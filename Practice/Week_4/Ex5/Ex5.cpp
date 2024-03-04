#include "Ex5.h"

Node* makeNode(int x){
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void readFile(Node *&head, int &x){
    ifstream input("input.txt");
    if(!input.is_open()){
        cout << "Can not open input.txt";
        return;
    }
    
    input >> x;
    input.ignore(1, '\n');

    int n;
    input >> n;
    Node *newNode = makeNode(n);

    if(n != 0){
        head = newNode;
    } else return;
    
    Node *tmp = head;
    while(input >> n){
        if(n == 0)
            break;
        else {    
            newNode = makeNode(n);
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;
    input.close();
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

void insertIntoSortedList(Node *&head, int x) {
    Node *newNode = makeNode(x);

    if (!head || head->data >= x) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *prev = head, *tmp = head->next;
    while (tmp && tmp->data < x) {
        prev = tmp;
        tmp = tmp->next;
    }

    newNode->next = tmp;
    prev->next = newNode;
}


void deleteList(Node *&head){
    Node *cur = head, *tmp = NULL;
    if (head == NULL) return;
    while(cur->next != NULL){
        tmp = cur;
        cur = cur->next;
        delete tmp;
    }

    delete cur;
}
