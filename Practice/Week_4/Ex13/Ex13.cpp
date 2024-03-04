#include "Ex13.h"

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

    input.ignore(1,'\n');
    input >> x;

    input.close();
}

bool checkLoopList(Node *&head, int x) {
    if (head == nullptr) return false;

    Node *tmp = head;
    Node *loopNode = nullptr;
    
    while (tmp != nullptr) {
        if (tmp->data == x) {
            loopNode = tmp;
        }
        tmp = tmp->next;
    }

    if (loopNode == nullptr) return false;

    Node *cur = head;
    while (cur->next != nullptr) cur = cur->next;

    cur->next = loopNode;
    return true;
}


void printList(Node *head, int x){
    ofstream output("output.txt");
    if (!output.is_open()){
        cout << "Cannot open this file";
        return;
    }

    if(head == NULL){
        output << "No data";
        return;
    }

    if(checkLoopList(head, x)) output << "Yes";
        else output << "No";

    output.close();
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