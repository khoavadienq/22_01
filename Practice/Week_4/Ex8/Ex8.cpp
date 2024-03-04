#include "Ex8.h"

Node* makeNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void readFile(Node*& head1, Node*& head2) {
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

    input.close();
}

Node* combineTwoLists(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    if (head1 == NULL && head2 == NULL) return NULL;
    
    Node* newList = NULL;
    Node* tmp = NULL;
    if (head2->data < head1->data) {
        newList = head2;
        head2 = head2->next;
    } else {
        newList = head1;
        head1 = head1->next;
    }

    tmp = newList;
    while (head1 != NULL && head2 != NULL) {
        if (head2->data < head1->data) {
            tmp->next = head2;
            head2 = head2->next;
        } else {
            tmp->next = head1;
            head1 = head1->next;
        }
        tmp = tmp->next;
    }

    if (head1 == NULL)
        tmp->next = head2;
    else
        tmp->next = head1;

    return newList;
}

void printList(Node* head) {
    ofstream output("output.txt");
    if (!output.is_open()) {
        cout << "Cannot open output.txt";
        return;
    }

    if (head == nullptr) {
        output << "No data";
        output.close();
        return;
    }

    while (head != nullptr) {
        output << head->data << " ";
        head = head->next;
    }

    output.close();
}

void deleteList(Node*& head) {
    Node* cur = head;
    while (head != nullptr) {
        cur = head;
        head = head->next;
        delete cur;
    }
}
