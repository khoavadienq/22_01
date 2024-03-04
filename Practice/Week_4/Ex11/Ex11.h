#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *makeNode(int x);
void readFile(int &x);
Node *turnNumIntoList(int x);
void printList(Node *head);
void deleteList(Node *&head);
