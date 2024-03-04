#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* makeNode(int x);

void readFile(Node *&head, int &x);

bool checkLoopList(Node *&head, int x);

void printList(Node *head, int x);

void deleteList(Node *&head);
