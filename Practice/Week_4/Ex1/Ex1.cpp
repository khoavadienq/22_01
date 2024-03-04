#include "Ex1.h"

Node* makeNode(int x){
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void readFile(Node *&head){
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

void removeAllX(Node *&head){
    int n;
    cout << "Input n: ";
    cin >> n;

    while(head->data == n) {
        if(head == NULL) {
            return;
        }
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    Node *tmp = head;
    if(tmp == NULL) return;

    while(tmp->next != NULL){
        if (tmp->next->data == n){
            Node *toDelete = tmp->next;
            tmp->next = toDelete->next;
            delete toDelete;
        } else tmp = tmp->next;
    }
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