#include "Ex10.h"

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

void print(unsigned int x){
    ofstream output("output.txt");
    if (!output.is_open()){
        cout << "Cannot open this file";
        return;
    }
    if(x == -1) output << "Dont accept negative nums";
        else output << x;

    output.close();
}

unsigned int changeListIntoNum(Node *head){
    if(head == NULL) return -1;
    if(head->next == NULL) return head->data;

    unsigned int sum = 0;
    while(head != nullptr){
        if(head->data >= 0){
            sum = head->data + sum * 10;
            head = head->next;
        } else return -1;
    }
    return sum;
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
