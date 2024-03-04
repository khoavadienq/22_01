#include "Ex7.h"

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
    ofstream output("output.txt", ios::out | ios::app);
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
    output << "\n";
    output.close();
}

Node* splitIntoTwoList(Node *&head) {
    Node *list1 = NULL, *list2 = NULL, *cur1 = NULL, *cur2 = NULL;
    Node *tmp = head;
    bool check = false;

    while(tmp != NULL){
        if(check){
            if(list2 == NULL){
                list2 = tmp;
                cur2 = list2;
            } else {
                cur2->next = tmp;
                cur2 = cur2->next;
            }
        } else {
            if(list1 == NULL){
                list1 = tmp;
                cur1 = list1;
            } else {
                cur1->next = tmp;
                cur1 = cur1->next;
            }
        }

        check = !check;
        tmp = tmp->next;
    }

    if(cur2 != NULL) cur2->next = NULL;
    if(cur1 != NULL) cur1->next = NULL;

    head =list1;
    return list2;
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
