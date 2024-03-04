#pragma once 

#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* makeNode(int x);

void readFile(Node *&head);

void reserveList(Node *&head);

void printList(Node *head);

void deleteList(Node *&head);
