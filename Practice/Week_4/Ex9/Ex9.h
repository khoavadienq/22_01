#pragma once 
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int x);
void readFile(Node*& head1, Node*& head2);
Node* combineTwoLists(Node* head1, Node* head2);
void printList(Node* head);
void deleteList(Node*& head);
